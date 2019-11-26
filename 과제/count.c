#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	FILE* fd;

	int nowParagraphNum = 0;
	char cha;
	int wordCount = 0;
	int charCount = 0;
	int nowStateInWord = 0;
	char str[100];
	int i = 0;
	
	if(argc == 1){
		printf("문자열을 입력하세요 : ");
		fgets(str, sizeof(str), stdin);

		while(str[i] != '\0'){
			if((str[i] >= 'A' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {
				charCount++;
				if(nowStateInWord == 0) {
					nowStateInWord = 1;
				}
			}
			else {
				if(nowStateInWord == 1) {
					if(str[i] == '(') {
						nowStateInWord = 2;
					}
					else if(str[i] == ' ' || str[i] == ',' || str[i] == '.') {
						nowStateInWord = 0;
						wordCount++;
					}
				}
				else if(nowStateInWord == 2) {
					if(str[i] == ')') {
						wordCount++;
						nowStateInWord = 0;
					}
				}
			}
			if(str[i] == '\n') {
				nowParagraphNum++;
				wordCount++;
			}
		i++;
		}		
	}
		
	else if(argc == 2) {
	
	fd = fopen(argv[1], "rt");

	if(fd == NULL) {
		printf("error\n");
		return 1;
	}

	while(feof(fd) == 0) {
		cha=fgetc(fd);
		if((cha >= 'A' && cha <= 'z') || (cha >= '0' && cha <= '9')) {
			charCount++;
			if(nowStateInWord == 0) {
				nowStateInWord = 1;
			}
		}
		else {
			if(nowStateInWord == 1) {
				if(cha == '(') {
					nowStateInWord = 2;
				}
				else if(cha == ' ' || cha == ',' || cha == '.') {
					nowStateInWord = 0;
					wordCount++;
				}
			}
			else if(nowStateInWord == 2) {
				if(cha == ')') {
					wordCount++;
					nowStateInWord = 0;
				}
			}
		}
		if(cha == '\n') {
			nowParagraphNum++;
 			wordCount++;
		}
	}
	fclose(fd);
	}
	
	else {
		printf("error\n");
		return 1;
	}

	printf("\n\nchar Num : %d, word Num : %d, paragraph Num : %d \n\n", charCount, wordCount, nowParagraphNum);

	return 0;
}	
