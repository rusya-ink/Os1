#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n;
    printf("Write lenght of array:\n");
    scanf("%u", &n);
    int *a = malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        a[i]=i;
    }
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    puts("");
    free(a);
    return 0;
}