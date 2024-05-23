//
//  07_02_swap2.c
//  prg1
//
//  Created by k24015kk on 2024/05/23.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int x,y,temp;
    
    printf("x y? ");
    scanf("%d %d",&x,&y);
    
    if(y<x){
        temp = y;
        y = x;
        x = temp;
    }
    
    
    printf("%d %d\n",x,y);
    
    return 0;
}
　 
