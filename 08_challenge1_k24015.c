//
//  08_challenge1_k24015.c
//  prg1
//
//  Created by k24015kk on 2024/06/06.
//

#include <stdio.h>


int main(int argc, const char * argv[]){
    
    int input,n=2;
    printf("input? ");
    scanf("%d",&input);

    
    
    while (input > 1) {
        if(input % n == 0){
            printf("%d",n);
            input = input / n;
            if(input != 1){
                printf(", ");
            }
        }else{
            n++;
        }
    }
    printf("\n");
    return 0;
}
