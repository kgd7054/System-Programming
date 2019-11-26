#include <stdio.h>

int main(int argc, char** argv)
{
	FILE* fp1;
	FILE* fp2;
	int state1, state2;
	char a, b;

	if (argc != 3) {
		printf("no\n");
		return 1;
	}

	fp1 = fopen(argv[1], "rt");
	fp2 = fopen(argv[2], "rt");

	if (fp1 == NULL || fp2 == NULL) {
		printf("no\n");
		return 1;
	}

	while (1) {
		if (feof(fp1) == 0 && feof(fp2) == 0) {
			a = fgetc(fp1);
			b = fgetc(fp2);

			if (a != b) {
				printf("파일이 %ld 부터 다릅니다.\n", ftell(fp1));
				break;
			}
		}

		else if (feof(fp1) != 0 && feof(fp2) == 0) {
			printf("파일이 %ld 부터 다릅니다.\n", ftell(fp2));
			break;
		}

		else if (feof(fp1) == 0 && feof(fp2) != 0) {
			printf("파일이 %ld부터 다릅니다.\n", ftell(fp1));
			break;
		}

		else {
			printf("두 파일은 같습니다.\n");
			break;
		}
	}

	state1 = fclose(fp1);
	state2 = fclose(fp2);

	if (state1 != 0 || state2 != 0) {
		printf("error\n");
		return 1;
	}

	return 0;
}
