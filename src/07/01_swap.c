//
//  07_01_swap.c
//  prg1
//
//  Created by k24015kk on 2024/05/23.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int x,y,temp;
    
    printf("x y? ");
    scanf("%d %d",&x,&y);
    
    temp = y;
    y = x;
    x = temp;
    
    printf("%d %d\n",x,y);
    
    return 0;
}
