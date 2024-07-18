#include <stdio.h>

int main(int argc, const char *argv[]) {
    int wallet = 1000;
    int amount;

    while(wallet > 0) {

        printf("amount? ");
        scanf("%d", &amount);

        if(amount == 0) {
            printf("取引終了\n");
            return 0;
        }

        wallet -= amount;

        printf("取引完了後: 残高: %d\n", wallet);
    }

    return 0;
}