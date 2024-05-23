//
//  07_06_fact.c
//  prg1
//
//  Created by k24015kk on 2024/05/23.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int n,i,x,kei;
    printf("x n? ");
    scanf("%d %d",&x,&n);
    
    kei = 1;

    for(i=1 ; i<=n ; i++){
        kei = kei * x;
    }
    
    printf("%d^%d = %d\n",x,n,kei);
    
    return 0;
}


