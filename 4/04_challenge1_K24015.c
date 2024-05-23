//
//  04_challenge1_K24015.c
//  prg1
//
//  Created by k24015kk on 2024/05/15.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int x,y;
    printf("x? ");
    scanf("%d",&x);

    y=x/100;
    x=x%100;
    y+=x/10*10;
    x=x%10;
    y+=x*100;
    
    printf("reverse = %d\n",y);
    
    return 0;
}
