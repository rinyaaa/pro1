//
//  04_issue1_K24015.c
//  prg1
//
//  Created by k24015kk on 2024/05/09.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int h,w;
    double bmi,hyo, h2;
    printf("height? ");
    scanf("%d",&h);
    printf("weight? ");
    scanf("%d" ,&w);
    hyo = (h-100)*0.9;
    h2= h*0.01;
    bmi= w/(h2*h2);
    printf("standardWeight = %f\n",hyo);
    printf("BMI = %f\n",bmi);
    return 0;
}
    
