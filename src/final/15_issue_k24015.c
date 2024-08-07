#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define map_height 21
#define map_width 21 // mapの範囲指定

typedef enum { map_floor,
               map_wall,
               map_start,
               map_goal } MazeCell;

MazeCell map[map_height][map_width];

int player1_x = 1; // プレーヤー1の初期位置（X座標）
int player1_y = 1; // プレーヤー1の初期位置（Y座標）

int player2_x = 2; // プレーヤー2の初期位置（X座標）
int player2_y = 1; // プレーヤー2の初期位置（Y座標）

// mapの初期化
void initialize_map() {
    for(int x = 0; x < map_height; x++) {
        for(int y = 0; y < map_width; y++) {
            if(x == player2_x && y == player2_y) {
                map[x][y] = map_floor;
            } else
                map[x][y] = map_wall;
        }
    }
}

int turn = 1; // プレーヤー1から開始

bool wall_break_flag = false;
bool b_flag = false;
bool break_flag = false;

void print_map() {
    system("clear"); // 画面をクリア
    for(int y = 0; y < map_height; y++) {
        for(int x = 0; x < map_width; x++) {
            if(x == player1_x && y == player1_y) {
                printf("\x1b[36mP1\x1b[39m");
            } else if(x == player2_x && y == player2_y) {
                printf("\x1b[32mP2\x1b[39m");
            } else {
                switch(map[y][x]) {
                case map_floor:
                    printf("  ");
                    break;
                case map_wall:
                    printf("##");
                    break;
                case map_start:
                    printf("  ");
                    break;
                case map_goal:
                    printf("\x1b[31mG \x1b[39m");
                    break;
                }
            }
        }
        printf("\n");
    }
}

void generate_map(int x, int y) {
    const int dirs[4][2] = {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};
    int order[4] = {0, 1, 2, 3};
    map[y][x] = map_floor;

    // 穴掘り法で方向をランダムにシャッフル
    for(int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }

    for(int i = 0; i < 4; i++) {
        int dx = dirs[order[i]][0];
        int dy = dirs[order[i]][1];
        int nx = x + dx;
        int ny = y + dy;
        if(nx >= 0 && nx < map_width && ny >= 0 && ny < map_height &&
           map[ny][nx] == map_wall) {
            map[ny - dy / 2][nx - dx / 2] = map_floor;
            map[ny][nx] = map_floor;
            generate_map(nx, ny);
        }
    }
}

// プレーヤーの動かせるコマを決めるもの
int roll_dice() {
    return rand() % 6 + 1; // 1から6までのランダムな数を返す
}

int rodom_wrop_x() { return rand() % 15 + 1; }
int rodom_wrop_y() { return rand() % 15 + 1; }

int rodom_wrop_2x() { return rand() % 15 + 1; }
int rodom_wrop_2y() { return rand() % 15 + 1; }

// 1文字の入力を取得
int getch(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt); // 既存の端末属性を取得
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // 行単位の入力無効と画面に表示しない設定
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // 新しい設定を即時に適用

    ch = getchar(); // 文字を取得

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // 端末属性を元に戻す
    return ch;
}

// プレイヤーの位置を更新
void update_player_position(int player, char input) {
    int newX, newY;

    if(player == 1) {
        newX = player1_x;
        newY = player1_y;
    } else {
        newX = player2_x;
        newY = player2_y;
    }

    // プレーヤーの新しい位置を計算
    switch(input) {
    case 'w': // 上
        newY -= 1;
        break;
    case 's': // 下
        newY += 1;
        break;
    case 'a': // 左
        newX -= 1;
        break;
    case 'd': // 右
        newX += 1;
        break;
    }

    // 新しい位置がマップ範囲内かどうかチェック
    if(newX >= 0 && newX < map_width && newY >= 0 && newY < map_height) {
        // 壁でない場合にのみ移動
        if(map[newY][newX] != map_wall) {
            if(player == 1) {
                player1_x = newX;
                player1_y = newY;
            } else {
                player2_x = newX;
                player2_y = newY;
            }
        }

        // プレイヤーが重なった場合の処理
        if(player1_x == player2_x && player1_y == player2_y) {
            int rodom_x = rodom_wrop_x();
            int rodom_y = rodom_wrop_y();

            int rodom_2x = rodom_wrop_2x();
            int rodom_2y = rodom_wrop_2y();

            // ワープ先が#だった時の処理
            while(map[rodom_y][rodom_x] != map_floor) {
                rodom_x = rodom_wrop_x();
                rodom_y = rodom_wrop_y();
            }

            player1_x = rodom_x;
            player1_y = rodom_y;

            while(map[rodom_2y][rodom_2x] != map_floor) {
                rodom_2x = rodom_wrop_2x();
                rodom_2y = rodom_wrop_2y();
            }

            player2_x = rodom_2x;
            player2_y = rodom_2y;
        }

        // ゴールに到達したら
        if(map[newY][newX] == map_goal) {
            print_map();

            if(player == 1) {
                printf("\x1b[36m");
            } else {
                printf("\x1b[32m");
            }
            printf("\n");
            printf("   ####    #####     ##     ####\n");
            printf("  ##  ##  ##   ##   ####     ##\n");
            printf(" ##       ##   ##  ##  ##    ##\n");
            printf(" ##       ##   ##  ##  ##    ##\n");
            printf(" ##  ###  ##   ##  ######    ##   #\n");
            printf("  ##  ##  ##   ##  ##  ##    ##  ##\n");
            printf("   #####   #####   ##  ##   #######\n");
            printf("\n");

            if(player == 1) {
                printf("######   ####       ##     ##  ##   #######  ######     ##     ##   ##   ####    ##   ##\n");
                printf(" ##  ##   ##       ####    ##  ##    ##   #   ##  ##   ###     ##   ##    ##     ###  ##\n");
                printf(" ##  ##   ##      ##  ##   ##  ##    ## #     ##  ##    ##     ##   ##    ##     #### ##\n");
                printf(" #####    ##      ##  ##    ####     ####     #####     ##     ## # ##    ##     ## ####\n");
                printf(" ##       ##   #  ######     ##      ## #     ## ##     ##     #######    ##     ##  ###\n");
                printf(" ##       ##  ##  ##  ##     ##      ##   #   ##  ##    ##     ### ###    ##     ##   ##\n");
                printf("####     #######  ##  ##    ####    #######  #### ##  ######   ##   ##   ####    ##   ##\n");
            } else {
                printf("######   ####       ##     ##  ##   #######  ######    ####    ##   ##   ####    ##   ##\n");
                printf(" ##  ##   ##       ####    ##  ##    ##   #   ##  ##  ##  ##   ##   ##    ##     ###  ##\n");
                printf(" ##  ##   ##      ##  ##   ##  ##    ## #     ##  ##      ##   ##   ##    ##     #### ##\n");
                printf(" #####    ##      ##  ##    ####     ####     #####     ###    ## # ##    ##     ## ####\n");
                printf(" ##       ##   #  ######     ##      ## #     ## ##    ##      #######    ##     ##  ###\n");
                printf(" ##       ##  ##  ##  ##     ##      ##   #   ##  ##  ##  ##   ### ###    ##     ##   ##\n");
                printf("####     #######  ##  ##    ####    #######  #### ##  ######   ##   ##   ####    ##   ##\n");
            }
            printf("プレーヤー%dがゴールです！\nおめでとうございます！\n",
                   player);
            exit(0); // プログラムを終了
        }
    }
}

// 壁を壊す機能
bool break_wall(int player, char direction) {
    int px, py;
    if(player == 1) {
        px = player1_x;
        py = player1_y;
    } else {
        px = player2_x;
        py = player2_y;
    }
    switch(direction) {
    case 'w': // 上
        if(py > 1 && map[py - 1][px] == map_wall) {
            map[py - 1][px] = map_floor;
            return true;
        }
        break;
    case 's': // 下
        if(py < map_height - 2 && map[py + 1][px] == map_wall) {
            map[py + 1][px] = map_floor;
            return true;
        }
        break;
    case 'a': // 左
        if(px > 1 && map[py][px - 1] == map_wall) {
            map[py][px - 1] = map_floor;
            return true;
        }
        break;
    case 'd': // 右
        if(px < map_width - 2 && map[py][px + 1] == map_wall) {
            map[py][px + 1] = map_floor;
            return true;
        }
        break;
    }
    return false;
}

int dice_animation() {
    int random;
    printf("\rサイコロを振っています...\n");
    for(int i = 0; i < 14; i++) {
        system("clear"); // 画面をクリア
        print_map();
        random = roll_dice();
        if(random == 1) {
            printf(" _____ \n"
                   "|     |\n"
                   "|  •  |\n"
                   "|_____|\n");
        } else if(random == 2) {
            printf(" _____ \n"
                   "|•    |\n"
                   "|     |\n"
                   "|____•|\n");

        } else if(random == 3) {
            printf(
                " _____ \n"
                "|•    |\n"
                "|  •  |\n"
                "|____•|\n");
        } else if(random == 4) {
            printf(" _____ \n"
                   "|•   •|\n"
                   "|     |\n"
                   "|•___•|\n");
        } else if(random == 5) {
            printf(" _____ \n"
                   "|•   •|\n"
                   "|  •  |\n"
                   "|•___•|\n");
        } else {
            printf(" _____ \n"
                   "|•   •|\n"
                   "|•   •|\n"
                   "|•___•|\n");
        }

        usleep(100000); // 0.1秒待機
    }
    printf("\rサイコロの目は...          \n");
    return random;
}

// 妨害が発生するかチェックし、発生した場合に処理を実行
int check_and_apply_interference(int player) {
    int interference_chance = rand() % 100;

    // 20%の確率で妨害が発生
    if(interference_chance < 20) {
        int interference_type = rand() % 3;

        switch(interference_type) {
        case 0:
            // 1ターン休み
            turn = (turn == 1) ? 2 : 1;
            return 0;
            // 壁の位置が入れ替わる
        case 1:
            initialize_map();
            generate_map(1, 1);
            map[1][1] = map_start;
            map[map_height - 2][map_width - 2] = map_goal;
            print_map();
            return 1;

        case 2: {
            int temp_x = player1_x;
            int temp_y = player1_y;
            player1_x = player2_x;
            player1_y = player2_y;
            player2_x = temp_x;
            player2_y = temp_y;
            return 2;
        }
        }
    }
    return -1;
}

void wait_start() {
    char ch;
    // ゲーム名
    system("clear");
    printf("\n");
    printf("##   ##    ##     #######  #######            #####   #######           ####      ####    #######  #######\n");
    printf("### ###   ####    #   ##    ##   #           ##   ##   ##   #            ##        ##      ##   #   ##   #\n");
    printf("#######  ##  ##      ##     ## #             ##   ##   ## #              ##        ##      ## #     ## #\n");
    printf("#######  ##  ##     ##      ####             ##   ##   ####              ##        ##      ####     ####\n");
    printf("## # ##  ######    ##       ## #             ##   ##   ## #              ##   #    ##      ## #     ## #\n");
    printf("##   ##  ##  ##   ##    #   ##   #           ##   ##   ##                ##  ##    ##      ##       ##   #\n");
    printf("##   ##  ##  ##   #######  #######            #####   ####              #######   ####    ####     #######\n");
    printf("\n");
    printf("全画面にしてください\n");
    printf("ゲームを開始するときは「s」を押してください\n");

    while((ch = getch()) != 's') {
        // 's'キーが押されるまで待機
    }
}
void player_change() {
    printf("\n");
    printf("######   ####       ##     ##  ##   #######  ######              ####   ##   ##    ##     ##   ##    ####   #######\n");
    printf(" ##  ##   ##       ####    ##  ##    ##   #   ##  ##            ##  ##  ##   ##   ####    ###  ##   ##  ##   ##   #\n");
    printf(" ##  ##   ##      ##  ##   ##  ##    ## #     ##  ##           ##       ##   ##  ##  ##   #### ##  ##        ## #\n");
    printf(" #####    ##      ##  ##    ####     ####     #####            ##       #######  ##  ##   ## ####  ##        ####\n");
    printf(" ##       ##   #  ######     ##      ## #     ## ##            ##       ##   ##  ######   ##  ###  ##  ###   ## #\n");
    printf(" ##       ##  ##  ##  ##     ##      ##   #   ##  ##            ##  ##  ##   ##  ##  ##   ##   ##   ##  ##   ##   #\n");
    printf("####     #######  ##  ##    ####    #######  #### ##             ####   ##   ##  ##  ##   ##   ##    #####  #######\n");
    printf("\n");
}

int main(void) {

    wait_start();

    srand(time(NULL));

    initialize_map();
    generate_map(1, 1); // スタート地点を(1,1)に設定
    map[1][1] = map_start;
    map[map_height - 2][map_width - 2] = map_goal;
    print_map();

    int dice_screen;
    int first = 0; // 最初の反復を示すフラグ変数
    int interference_cheak;
    int moves_count = 0;
    int turn_rest;
    int remaining_moves = 0;

    bool b_flag = false;
    bool player1_break = true;
    bool player2_break = true;
    bool wall_break_flag = false;

    while(1) {
        print_map();
        if(first) {
            if(moves_count == 0) {
                if(interference_cheak == 0) {
                    turn_rest = (turn == 1) ? 2 : 1;
                    printf("player%dは1ターン休みです\n", turn_rest);
                } else if(interference_cheak == 1) {
                    printf("壁の位置がランダムで変更されます\n");
                } else if(interference_cheak == 2) {
                    printf("playerがいれかわります\n");
                }
            }
        }

        if(first) {
            if(moves_count == 0) {
                player_change(); // player change表示
            }
        } else {
            first = 1;
        }

        // 現在のプレーヤーのターンを表示
        if(remaining_moves == 0) {
            printf("プレーヤー%dのターンです。サイコロを振ってください（Enterキーを押してください）...\n", turn);
            getchar();                          // プレーヤーがEnterキーを押すまで待つ
            remaining_moves = dice_animation(); // サイコロを振るアニメーション
            dice_screen = remaining_moves;
            printf("出た目は: %d\n", remaining_moves);
        }
        printf("%dのターンです\n", turn);
        printf("あと%d回動かせます\n", remaining_moves - moves_count);

        // 壁を壊した時、メッセージを表示
        if(b_flag) {
            if(turn == 1) {
                if(player1_break) {
                    if(wall_break_flag) {
                        printf("壁が破壊されました。\n");
                        wall_break_flag = false;
                        player1_break = false;
                    } else {
                        printf("選択した箇所に対象ブロックがありません\n");
                    }
                } else {
                    printf("\x1b[33m壊すのは一回しか行えません\x1b[39m\n");
                }
            } else if(turn == 2) {
                if(player2_break) {
                    if(wall_break_flag) {
                        printf("壁が破壊されました。\n");
                        wall_break_flag = false;
                        player2_break = false;
                    } else {
                        printf("選択した箇所に対象ブロックがありません\n");
                    }
                } else {
                    printf("\x1b[43m壊すのは一回しか行えません\x1b[39m\n");
                }
            }
            b_flag = false; // b_flagをリセットする
        }

        char input = getch(); // キーボードの入力を取得
        if(input == 'p') {
            break; // 'p'キーで終了5
        }

        // 壁を壊す処理
        if(input == 'b') {
            printf("どの方向の壁を壊しますか？(w/a/s/d):\n ");
            char direction = getch(); // 壁を壊す方向を取得
            b_flag = true;
            if((turn == 1 && player1_break) || (turn == 2 && player2_break)) {
                wall_break_flag = break_wall(turn, direction);
            }
        } else {
            // 移動前の位置を保存
            int prev_x, prev_y;
            if(turn == 1) {
                prev_x = player1_x;
                prev_y = player1_y;
            } else {
                prev_x = player2_x;
                prev_y = player2_y;
            }

            update_player_position(turn, input); // プレーヤーの位置を更新

            // 移動が有効かチェック
            int moved = 0;
            if(turn == 1 && (prev_x != player1_x || prev_y != player1_y)) {
                moved = 1;
            } else if(turn == 2 && (prev_x != player2_x || prev_y != player2_y)) {
                moved = 1;
            }

            // 移動した場合にのみ動かせる回数を減らす
            if(moved) {
                moves_count++;
            }

            // 現在のプレーヤーがサイコロ分移動したかどうかをチェック
            if(moves_count == remaining_moves) {
                // ターンを交代

                turn = (turn == 1) ? 2 : 1;
                remaining_moves = 0;
                moves_count = 0;
                // ターン終了後に妨害をチェックして適用
                interference_cheak = check_and_apply_interference(turn);
            }
        }

        usleep(100000); // 0.1秒待機
    }

    return 0;
}


//時間制限を作った！（嘘）