//
//  08_07_tillzero3.c
//  prg1
//
//  Created by k24015kk on 2024/06/01.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int wallet,amount;
    
    wallet = 1000;
    
    while (wallet > 0){
        printf("amount? ");
        scanf("%d",&amount);
        
        if(amount == 0){
            printf("取引終了\n");
            return 0;
        }
        
        if(amount < 0){
            printf("無効です\n");
            continue;
        }
        
        wallet = wallet - amount ;
        
        printf("残高: %d\n",wallet);
    }
    
}
