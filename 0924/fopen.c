#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char *argv[])
{
	int fd;
	if((fd = open(argv[1], O_RDWR)) == -1)
	   printf("file open errer\n");
	else 
	   printf("file %s open clear : %d\n", argv[1], fd);

	close(fd);
	exit(0);
}
