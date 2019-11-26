#include <stdio.h>
#define MAXLINE 80

int main(int argc, char *argv[])
{
	FILE *fp;
	int line = 0;
	char buffer[MAXLINE];

	if(argc != 2) {
	  fprintf(stderr, "use : line file name\n");
	  exit(1);
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
	  fprintf(stderr, "file open23 line++");
	  exit(2);
	}

	while(fgets(buffer, MAXLINE, fp) != NULL) {
	  line++;
	  printf("%3d %s", line, buffer);
	}
	exit(0);
}