#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define map_width (40)
#define map_height (20)

char map[map_height][map_width + 1]; // 改行文字を処理するために1を追加
int playerX = map_width / 2;  // プレーヤーの初期位置（X座標）
int playerY = map_height / 2; // プレーヤーの初期位置（Y座標）

// 1文字の入力を取得
int getch(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt); // 既存の端末属性を取得
    newt = oldt;
    newt.c_lflag &=
        ~(ICANON | ECHO); // 非カノニカルモードとエコーモードを無効にする
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
            if(x == playerX && y == playerY) {
                printf("P"); // プレーヤーの位置
            } else {
                printf("%c", map[y][x]);
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

// プレーヤーの位置を更新
void update_player_position(char input) {
    int newX = playerX;
    int newY = playerY;

    // プレーヤーの新しい位置を計算
    switch(input) {
    case 'w': // 上
        newY = playerY > 0 ? playerY - 1 : playerY;
        break;
    case 's': // 下
        newY = playerY < map_height - 1 ? playerY + 1 : playerY;
        break;
    case 'a': // 左
        newX = playerX > 0 ? playerX - 1 : playerX;
        break;
    case 'd': // 右
        newX = playerX < map_width - 1 ? playerX + 1 : playerX;
        break;
    }

    // 新しい位置が壁でない場合にのみ移動
    if(map[newY][newX] != '#') {
        playerX = newX;
        playerY = newY;
    }

    // ゴールに到達したかを確認
    if(map[newY][newX] == 'G') {
        draw_screen();
        printf("ゴールです！おめでとうございます！\n");
        exit(0); // プログラムを終了
    }
}

int main(void) {
    load_map_from_file(
        "/Users/k24015kk/src/prg1K/prg1/src/final/map.txt"); // 絶対パスでマップファイルを読み込む

    while(1) {
        draw_screen();        // 画面を描画
                              // キーボードの入力を検出
        char input = getch(); // 入力を取得
        if(input == 'q')
            break;                     // 'q'キーで終了
        update_player_position(input); // プレーヤーの位置を更新

        usleep(100000); // 0.1秒待機
    }

    return 0;
}