#include <stdio.h>

void print_center_triangle(int h){
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
        puts("");
    }
}

void print_left_triangle(int h){
    for(int i=0; i<h; i++){

        for(int j=0; j<i+1; j++){
            putc('*', stdout);
        }
        puts("");
    }
}

void print_right_triangle(int h){
    for(int i=0; i<h; i++){
        for(int j=0; j<h-i-1; j++){
            putc(' ', stdout);
        }
        for(int j=0; j<i+1; j++){
            putc('*', stdout);
        }
        puts("");
    }
}

void print_romb(int h){
    int c=0;
    if(h%2==0){
        c=1;
    }
    h=h/2+c;
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
        puts("");
    }
    for(int i=h-1; i>=0; i--){
        for(int j=0; j<h-i-1; j++){
            putc(' ', stdout);
        }
        for(int j=0; j<2*i+1; j++){
            putc('*', stdout);
        }
        for(int j=0; j<h-i-1; j++){
            putc(' ', stdout);
        }
        puts("");
    }
}

void print_square(int h){
    for(int i=0; i<h; i++){
        for(int j=0; j<h; j++){
            putc('*', stdout);
        }
        puts("");
    }
}

int main(int argc, char **argv)
{
    int h, type=0;
    if(argc<=2){
        puts("Give two parameters:\nFirst is the type of figure according to:\n"
             "\t1 - for left triangle\n\t2 - for center triangle\n\t3 - for right triangle\n"
             "\t4 - for square.");
        puts("Second is height of figure.");
    }else{
        sscanf(argv[1] ,"%d", &type);
        sscanf(argv[2] ,"%d", &h);
    }

    switch(type){
        case 1:{
            print_left_triangle(h);
            break;
        }
        case 2:{
            print_center_triangle(h);
            break;
        }
        case 3:{
            print_right_triangle(h);
            break;
        }
        case 4:{
            print_square(h);
            break;
        }
    }


    return 0;

}
