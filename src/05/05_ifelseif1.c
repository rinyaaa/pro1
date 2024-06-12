//
//  05_05_ifelseif1.c
//  prg1
//
//  Created by k24015kk on 2024/05/15.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a;
    printf("a? ");
    scanf("%d",&a);
    if(a>0){
        printf("a は 正の値です\n");
        printf("計算終了\n");
        
    }else if(a==0){
        printf("aは0です\n");
        printf("計算終了\n");
    }else{
        printf("a は 負の値です\n");
        printf("計算終了\n");
    }
   
    return 0;
}
