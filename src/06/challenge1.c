//
//  06_challenge1_K24015.c
//  prg1
//
//  Created by k24015kk on 2024/05/22.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int i,n,isPrimeNumber;
    isPrimeNumber = 0;
    printf("n? ");
    scanf("%d",&n);
    
    for(i=2 ; i<n ; i++){
        if(n % i == 0){
            isPrimeNumber = 1;
        }
    }

    if(isPrimeNumber==1 || n==0 || n==1){
        printf("素数ではありません\n");
        
    }else{
        printf("素数です\n");
    }
    return 0;
}
