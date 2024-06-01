//
//  08_05_tillzero.c
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
        
        wallet = wallet - amount ;
        
        printf("残高: %d\n",wallet);
    }
    return 0;
}
