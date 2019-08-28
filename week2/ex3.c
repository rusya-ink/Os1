#include <stdio.h>

int main(int argc, char **argv)
{
    int h;
    sscanf(argv[1], "%d", &h);


    for(int i=0; i<h; i++){
        for(int j=0; j<h-i-1; j++){
            putc(' ', stdout);
        }
        for(int j=0; j<2*i+1; j++){
            putc('*', stdout);
        }
        for(int j=0; j<h-i-1; j++){
            putc(' ', stdout);
        }
        puts("\n");
    }
    return 0;

}