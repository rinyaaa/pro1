//
//  05_07_ifand.c
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
    if(a>0 && b>0){
        printf("aとbは正です\n");
        
    }else{
        printf("aとbのどちらかは負もしくは0です\n");
    }
   
    return 0;
}
