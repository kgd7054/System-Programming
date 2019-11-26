#include <stdio.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int fd, id;
	struct student record;
	struct flock lock;

	if(argc < 2) {
	  fprintf(stderr,"use : %s file\n", argv[0]);
	  exit(1);
	}

	if((fd = open(argv[1], O_RDONLY)) == -1) {
	  perror(argv[1]);
	  exit(2);
	}

	printf("\n student number :");
	while(scanf("%d",&id) == 1) {
	  lock.l_type = F_RDLCK;
	  lock.l_whence = SEEK_SET;
	  lock.l_start = (id-START_ID)*sizeof(record);
	  lock.l_len = sizeof(record);
	  if(fcntl(fd, F_SETLKW, &lock) == -1) {
	    perror(argv[1]);
	    exit(3);
	  }

	lseek(fd, (id-START_ID)*sizeof(record), SEEK_SET);
	if((read(fd, (char *) &record, sizeof(record)) >0) && (record.id != 0))
	  printf(" name : %s\t number : %d\t score : %d\n", record.name, record.id, record.score);
	else printf("record %d no\n", id);

	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("\n enter student number : ");
	}

	close(fd);
	exit(0);
}
