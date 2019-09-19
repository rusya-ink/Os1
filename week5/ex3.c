#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
int to_produce=1, to_consume=0;
int food=0;
void *consume(){
    while(1){
        if(to_consume){
            food--;
            if(food=0){
                to_consume=0;            
            }
            if(food<10){
                to_produce=1;            
            }

        }
    }
        
}
int check;
void *produce(){
    check=0;
    while(1){
        if(to_produce){
            food++;
            if(food>0){
                to_consume=1;
            }
            if(food>=10){
                to_produce=0;            
            }        
        }
        if(time(0)%60==0&&check==0){
            check=1;
            printf("food: %d\n", food);        
        }else if(time(0)%60!=0&&check==1){
            check=0;        
        }
    }
}

int main(){

    pthread_t pthread1, pthread2;
    pthread_create(&pthread1, NULL, produce, NULL);
    pthread_create(&pthread2, NULL, consume, NULL);
    pthread_join(pthread1,NULL);
    pthread_join(pthread2,NULL);
    return 0;
}

