//
//  07_09_ways.c
//  prg1
//
//  Created by k24015kk on 2024/05/23.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int n,x,i,j,k,count;
    printf("n x? ");
    scanf("%d %d",&n,&x);
    count = 0;
    
    for (i = 1 ; i <= n ; i++) {
          for (j = 1 ; j <= n ; j++) {
              for (k = 1 ; k <= n ; k++) {
                  if (i + j + k == x) {
                      printf("%d%d%d\n",i,j,k);
                      count = count + 1;
                  }
              }
          }
      }
    printf("組合せの数: %d\n",count);
    return 0;
}
