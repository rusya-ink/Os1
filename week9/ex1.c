#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

#define R 128;

struct page{
    int number;
    int priority;
};

int main(int charc, char** argv){

    int n = atoi(argv[1]);
    struct page* pages;
    pages = malloc(n*sizeof(struct page));

    struct page empty_page;
    empty_page.number=-1;
    for(int i=0; i<n; i++){
        pages[i]=empty_page;    
    }

    FILE *inp;
    inp = fopen("Lab 09 input.txt", "r");
    int misses, hits=0, num_inputs=0;

    struct page new_page;
    while(fscanf(inp, "%d", &(new_page.number))>0){
        num_inputs++;
        new_page.priority=R;
        //printf("%d\n", new_page.number);
        
        int pos=0, empty=0, hit=0;
        for(int j=0; j<n; j++){
        
            if(pages[j].number==-1&&!hit){
                pos=j;
                empty=1;     
            }else if(pages[j].number!=new_page.number){
                if(pages[j].priority<pages[pos].priority&&!empty){
                    pos=j;                
                }   
                pages[j].priority/=2;         
            }else{
                pos=j;
                hit=1;
                pages[j].priority/=2;
                pages[j].priority+=new_page.priority;
            }
            
        }
        if(!hit){
            pages[pos]=new_page;        
        }else{
            printf("%d\n", new_page.number);            
        }
        hits+=hit;
    }

    printf("hits/misses: %d/%d\n", hits, num_inputs-hits);
    return 0;
}
