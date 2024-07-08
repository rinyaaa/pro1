#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define map_height 31
#define map_width 41 // mapの範囲指定

typedef enum { map_floor, map_wall, map_start, map_goal } MazeCell;

MazeCell map[map_height][map_width];

void initialize_map() {
    for(int y = 0; y < map_height; y++) {
        for(int x = 0; x < map_width; x++) {
            map[y][x] = map_wall;
        }
    }
}

int player1_x = 1; // プレーヤー1の初期位置（X座標）
int player1_y = 1; // プレーヤー1の初期位置（Y座標）

int player2_x = 2; // プレーヤー2の初期位置（X座標）
int player2_y = 1; // プレーヤー2の初期位置（Y座標）

int turn = 1; // プレーヤー1から開始

void print_map() {
    system("clear"); // 画面をクリア
    for(int y = 0; y < map_height; y++) {
        for(int x = 0; x < map_width; x++) {
            if(x == player1_x && y == player1_y) {
                printf("\x1b[31mP1\x1b[39m");
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
                    printf("G ");
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

int rodom_wrop_1() { return rand() % map_width - 2; }
int rodom_wrop_2() { return rand() % map_height - 2; }

// 1文字の入力を取得
int getch(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt); // 既存の端末属性を取得
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // 行単位の入力無効と画面に表示しない設定
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
            int rodom_x = rodom_wrop_1();
            int rodom_y = rodom_wrop_2();
            // ワープ先が#だった時の処理
            while(map[rodom_y][rodom_x] != map_floor) {
                rodom_x = rodom_wrop_1();
                rodom_y = rodom_wrop_2();
            }

            player1_x = rodom_x;
            player1_y = rodom_y;

            player2_x = rodom_y;
            player2_y = rodom_x;
        }

        // ゴールに到達したら
        if(map[newY][newX] == map_goal) {
            print_map();
            printf("プレーヤー%dがゴールです！\nおめでとうございます！\n",
                   player);
            exit(0); // プログラムを終了
        }
    }
}

int main(void) {
    srand(time(NULL));

    initialize_map();
    generate_map(1, 1); // スタート地点を(1,1)に設定
    map[1][1] = map_start;
    map[map_height - 2][map_width - 2] = map_goal;
    print_map();

    int moves_count = 0;
    int dice = 0;
    int dice_screen = 0;

    while(1) {
        print_map();
        // 最初だけサイコロを振る
        if(moves_count == 0) {
            dice = roll_dice();
            dice_screen = dice;
        }

        // 現在のプレーヤーのターンを表示
        printf("プレーヤー%dのターンです。\n", turn);
        printf("サイコロの目は%dでした\n", dice_screen);
        printf("あと%d回動かせます\n", dice - moves_count);

        // キーボードの入力を検出
        char input = getch(); // 入力を取得
        if(input == 'q')
            break; // 'q'キーで終了

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
        if(moves_count == dice) {
            // ターンを交代
            if(turn == 1) {
                turn = 2;
            } else {
                turn = 1;
            }
            moves_count = 0;
        }

        usleep(100000); // 0.1秒待機
    }

    return 0;
}