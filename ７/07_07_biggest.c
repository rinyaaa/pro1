//
//  07_07_biggest.c
//  prg1
//
//  Created by k24015kk on 2024/05/23.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int x,i,max;
    
    max = 0;
    for(i=1 ; i<=5 ; i++){
        printf("%d? ",i);
        scanf("%d",&x);
        
        if(max <= x){
            max = x;
        }
    }
    printf("max = %d\n",max);
  
    return 0;
}

