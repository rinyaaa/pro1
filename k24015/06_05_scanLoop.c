//
//  06_05_scanLoop.c
//  prg1
//
//  Created by k24015kk on 2024/05/22.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a,i;
    for(i=1;i<=5;i++){
        printf("a? ");
        scanf("%d",&a);
        
        printf("%d: %d\n",i,a);
    }
    
    return 0;
}
