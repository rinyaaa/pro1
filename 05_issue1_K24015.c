//
//  05_issue1_K24015.c
//  prg1
//
//  Created by k24015kk on 2024/05/16.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int x;
    printf("x? ");
    scanf("%d",&x);
    
    
    if(x % 2 == 0 && x != 0){
        printf("2の倍数です\n");
    }else{
        printf("2の倍数ではありません\n");
    }
    if(x % 3 == 0 && x != 0){
        printf("3の倍数です\n");
    }else{
        printf("3の倍数ではありません\n");
    }
        return 0;
}
