#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char * c = malloc(256*sizeof(char));

    fgets(c, 256, stdin);
    int len = strlen(c);
    char reverse[len+1];
    for(int i=0; i<len; i++){
        reverse[i]=c[len-i-1];
    }
    reverse[len]=0;
    free(c);
    printf(reverse);
    return 0;
}

