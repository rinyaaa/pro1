//
//  07_03_swap3.c
//  prg1
//
//  Created by k24015kk on 2024/05/23.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int x,y,z,temp;
    
    printf("x y z? ");
    scanf("%d %d %d",&x,&y,&z);
  
        if(y<x){
            temp = y;
            y = x;
            x = temp;
        }
        if(z<x){
            temp = z;
            z = x;
            x = temp;
        }
        if(z<y){
            temp = z;
            z = y;
            y = temp;
        }
    
    
    
    
    printf("%d %d %d\n",x,y,z);
    
    return 0;
}
