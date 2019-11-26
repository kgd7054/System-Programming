#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	printf("Hello\n");
	sleep(atoi(argv[1]));
	printf("Bye\n");
}
