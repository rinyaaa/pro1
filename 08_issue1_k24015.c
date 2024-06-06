//
//  08_issue1_k24015.c
//  prg1
//
//  Created by k24015kk on 2024/06/06.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int wallet,bank,amount;
    
    wallet = 1000;
    bank= 1000;
    
    
    
    while (wallet > 0 && bank > 0){
        
        if(amount == 0){
            printf("取引終了\n");
            break;
        }
        
        
        printf("amount? ");
        scanf("%d",&amount);
        
        if(amount>0){
            bank = bank - amount;
            wallet = wallet + amount;
            printf("銀行: %d 財布: %d\n",bank,wallet);
        }
        
        if(amount<0){
            wallet = wallet + amount;
            bank = bank - amount;
            printf("銀行: %d 財布: %d\n",bank,wallet);
        }
    }
    return 0;
}
