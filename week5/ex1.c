#include <pthread.h>
#include <stdio.h>

void pthread_print(void){

         printf("thread id: %d\n", pthread_self());
         printf("some text %d\n", pthread_self());
         pthread_exit(0);

}

int main(void){

    pthread_t pthread;
    int n=7;
    for(int i=0; i<n; i++){
        pthread_create(&pthread, NULL, pthread_print, NULL);
        printf("thread creation: %d\n", pthread);
        pthread_join(pthread,NULL);
    }

    printf("end\n");
    return 0;
}

