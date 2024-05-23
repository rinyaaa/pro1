//
//  03_issue1_K24015.c
//  prg1
//
//  Created by k24015kk on 2024/04/25.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a,b,c,d ;
    a = 6;
    b = 4;
    c = 2;
    d = a-(b/c);
    
    printf("%d - (%d / %d) = %d\n",a,b,c,d);
    return 0;
}
