#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define map_width (83)
#define map_height (31)

char map[map_height][map_width];
int player1_x = 1; // プレーヤー1の初期位置（X座標）
int player1_y = 2; // プレーヤー1の初期位置（Y座標）

int player2_x = 2; // プレーヤー2の初期位置（X座標）
int player2_y = 1; // プレーヤー2の初期位置（Y座標）

int turn = 1; // プレーヤー1から開始

// プレーヤーの動かせるコマを決めるもの
int roll_dice() {
    srand(time(NULL));     // 乱数シードの初期化
    return rand() % 6 + 1; // 1から6までのランダムな数を返す
}

int rodom_wrop_x() {
    srand(time(NULL)); // 乱数シードの初期化
    return rand() % 40 + 1;
}

int rodom_wrop_y() {
    srand(time(NULL)); // 乱数シードの初期化
    return rand() % 18 + 1;
}

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

// 画面を描画
void draw_screen() {
    system("clear"); // 画面をクリア
    for(int y = 0; y < map_height; y++) {
        for(int x = 0; x < map_width; x++) {
            if(x == player1_x && y == player1_y) {
                printf("1"); // プレーヤー1の位置に出力
            } else if(x == player2_x && y == player2_y) {
                printf("2"); // プレーヤー2の位置に出力
            } else {
                printf("%c", map[y][x]); // mapを出力
            }
        }
        printf("\n");
    }
}

// ファイルからマップを読み込む
void load_map_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        perror(
            "ファイルが開けませんでした"); // ファイルを開けなかった場合のエラーメッセージ
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < map_height; i++) {
        if(fgets(map[i], map_width + 1, file) == NULL) { // 各行を読み込む
            perror(
                "ファイルの行を読み込めませんでした"); // 行を読み込めなかった場合のエラーメッセージ
            fclose(file);
            exit(EXIT_FAILURE);
        }
        // 改行文字が存在する場合は削除
        map[i][strcspn(map[i], "\n")] = '\0';
    }

    fclose(file); // ファイルを閉じる
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

    // 壁でない場合にのみ移動
    if(map[newY][newX] != '#') {
        if(player == 1) {
            player1_x = newX;
            player1_y = newY;
        } else {
            player2_x = newX;
            player2_y = newY;
        }
    }
    int rodom_x = 0;
    int rodom_y = 0;
    if(player1_x == player2_x && player1_y == player2_y) {
        rodom_x = rodom_wrop_x();
        rodom_y = rodom_wrop_y();
        player1_x = rodom_x;
        player2_y = rodom_y;
    }

    // ゴールに到達したら
    if(map[newY][newX] == 'G') {
        draw_screen();
        printf("プレーヤー%dがゴールです！\nおめでとうございます！\n", player);
        exit(0); // プログラムを終了
    }
}

int main(void) {
    load_map_from_file(
        "/Users/k24015kk/src/prg1K/prg1/src/final/map.txt"); // 絶対パスでマップファイルを読み込む

    int moves_count = 0;
    int dice = 0;
    int dice_screen = 0;

    while(1) {
        draw_screen(); // 画面を描画

        // 最初だけサイコロを振る
        if(moves_count == 0) {
            dice = roll_dice();
            dice_screen = dice;
        }

        // 現在のプレーヤーのターンを表示
        printf("プレーヤー%dのターンです。\n", turn);
        printf("サイコロの目は%dでした\n", dice_screen);
        printf("あと%d回動かせます", dice - moves_count);

        // キーボードの入力を検出
        char input = getch(); // 入力を取得
        if(input == 'q')
            break; // 'q'キーで終了

        // 移動前の位置を保存
        int prev_x, prevY;
        if(turn == 1) {
            prev_x = player1_x;
            prevY = player1_y;
        } else {
            prev_x = player2_x;
            prevY = player2_y;
        }

        update_player_position(turn, input); // プレーヤーの位置を更新

        // 移動が有効かチェック
        int moved = 0;
        if(turn == 1 && (prev_x != player1_x || prevY != player1_y)) {
            moved = 1;
        } else if(turn == 2 && (prev_x != player2_x || prevY != player2_y)) {
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