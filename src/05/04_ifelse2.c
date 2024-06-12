//
//  05_04_ifelse2.c
//  prg1
//
//  Created by k24015kk on 2024/05/15.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a,b;
    printf("a? ");
    scanf("%d",&a);
    printf("b? ");
    scanf("%d",&b);
    if(a>b){
        printf("a は b 以上です\n");
        
    }else{
        printf("a は b 未満です\n");
    }
   
    return 0;
}
