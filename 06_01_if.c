//
//  06_01_if.c
//  prg1
//
//  Created by k24015kk on 2024/05/22.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a;
    printf("a? ");
    scanf("%d",&a);

    if(a>0){
        printf("aは正です\n");
        
    }else if(a==0){
        printf("aは0です\n");
    }else{
        printf("aは負の値です");
    }
   
    return 0;
}
