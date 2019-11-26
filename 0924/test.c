#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void)
{
	struct stat buf;
	stat("test1.txt", &buf);
	printf("st_mode = %o\n", buf.st_mode);

	return 0;
}
