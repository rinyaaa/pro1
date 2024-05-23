//
//  06_10_qq2.c
//  prg1
//
//  Created by k24015kk on 2024/05/22.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int i,j,n;
    printf("n? ");
    scanf("%d",&n);
    
    for(i=n ; i<=n+2 ; i++){
        for(j=1 ; j<=9 ; j++){
            printf("%d x %d = %d\n",i,j,i*j);
        }
        
    }
    
    return 0;
}
