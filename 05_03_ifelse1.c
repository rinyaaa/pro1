//
//  05_03_ifelse1.c
//  prg1
//
//  Created by k24015kk on 2024/05/15.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a;
    printf("a? ");
    scanf("%d",&a);
    if(a>=0){
        printf("aは正の値もしくは0です\n");
        printf("計算終了\n");
        
    }else{
        printf("aは負の値です\n");
        printf("計算終了\n");
    }
   
    return 0;
}
