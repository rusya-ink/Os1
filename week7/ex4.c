#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void * my_realloc(void * ptr, size_t size, size_t old_size){
    void * data;
    if(ptr!=NULL){
        if(size>0){
            data = malloc(old_size);
            memcpy(ptr, data, old_size);
        }
        free(ptr);
    }
    if(size>0){
        ptr = malloc(size);
        if(old_size>size){
            if(old_size!=-1){
                memcpy(data, ptr, size);
            }
        }else{
            if(old_size!=-1){
                memcpy(data, ptr, old_size);
            }
        }

    }
    return ptr;
}

int main(){

}
