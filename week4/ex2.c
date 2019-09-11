#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	for(int i=0; i<5; i++){
		pid_t n = fork();
		sleep(5);
	}
    return 0;
}
