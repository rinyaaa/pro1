//
//  06_issue1_k24015.c
//  prg1
//
//  Created by k24015kk on 2024/05/22.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int n,i,height;
    double sum;
    sum=0;
    printf("人数? ");
    scanf("%d",&n);
    for(i=1 ; i<=n ; i++){
        printf("%d人目の身長は？",i);
        scanf("%d",&height);
        sum = height + sum;
    }
    sum = sum/n;
    printf("%f\n",sum);
    return 0;
}
