#include <stdio.h>
#include <time.h>

int main() {
    int seconds;
    clock_t start_time, end_time;

    printf("何秒を制限としますか？");
    scanf("%d", &seconds);

    start_time = clock(); // 開始時間を記録

    while(seconds > 0) {
        end_time = clock();
        // 経過時間が1秒（CLOCKS_PER_SEC）以上経過した場合
        if((end_time - start_time) >= CLOCKS_PER_SEC) {
            printf("\r%d", seconds); // \rを使って同じ行を上書き
            fflush(stdout); // 標準出力をフラッシュして即座に表示
            start_time = clock(); // 再度開始時間をリセット
            seconds--;            // カウントを減らす
        }
    }

    printf("\nカウントダウン終了\n");

    return 0;
}