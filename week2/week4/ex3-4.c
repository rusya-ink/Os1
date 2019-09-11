#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    printf("q - to exit\n");
    char s[256];
    while(1){
        fgets(s, 256, stdin);
        if(s[0]=='q'&&s[1]<=32)
        {
           return 0;
        }
        else
        {
            system(s);
        }
    }
    return 0;
    
}
