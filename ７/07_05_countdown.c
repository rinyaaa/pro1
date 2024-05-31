//
//  07_05_countdown.c
//  prg1
//
//  Created by k24015kk on 2024/05/23.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int n,i;
    printf("n? ");
    scanf("%d",&n);
    
    for(i=n ; 1<=i ; i--){
        printf("%d\n",i);
    }
   
    
    return 0;
}
