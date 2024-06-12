//
//  05_challenge1_K24015.c
//  prg1
//
//  Created by k24015kk on 2024/05/16.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int dayofweek,time,isopen;
    
    printf("曜日? ");
    scanf("%d",&dayofweek);
    printf("時間帯? ");
    scanf("%d",&time);
    
    if(dayofweek==0 && time==0){
        printf("診断は行ってません\n");
    }else if(dayofweek==1 || dayofweek==2 || dayofweek==4 || dayofweek==5){
        printf("診断を行っています\n");
    }else if(dayofweek==3 && time==0){
        printf("診断を行っています\n");
    }else if(dayofweek==3 && time==1){
        printf("診断は行ってません\n");
    }else if(dayofweek==6 && time==1){
        printf("診断を行っています\n");
    }else{
        printf("診断は行ってません\n");
    }
    
    return 0;
}
    
