//
//  04_02_rectangle.c
//  prg1
//
//  Created by k24015kk on 2024/05/09.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    double x,y,z ;
    printf("width? ");
    scanf("%lf",&x);
    printf("height? ");
    scanf("%lf",&y);
    z=x*y;
    printf("area = %f\n",z);

    return 0;
}

