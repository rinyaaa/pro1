//
//  04_03_roundoff.c
//  prg1
//
//  Created by k24015kk on 2024/05/09.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int nx;
    double dx ;
    printf("dx? ");
    scanf("%lf",&dx);
    printf("dx/2 = %f\n",dx/2);
    nx = dx;
    
    printf("nx = %d\n",nx);
    printf("nx/2 = %d\n",nx/2);
    return 0;
}
