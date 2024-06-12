//
//  08_01_rectangle.c
//  prg1
//
//  Created by k24015kk on 2024/06/01.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int w,h,i,j;
    
    printf("h w? ");
    scanf("%d %d", &h, &w);

    for(i = 1 ; i <= h ; i++){
        for(j = 1 ; j <= w ; j++){
            putchar('#');
            
        }
        putchar('\n');
    }
    return 0;
}

