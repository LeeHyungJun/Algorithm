#include <stdio.h>

int main() {
	int i, j, k, testCase=0, number=0;
	FILE * fp;
	errno_t errno;
	errno= fopen_s(&fp, "input.txt", "r");
	fscanf_s(fp, "%d", testCase, sizeof(int)*3);
	printf("%d", testCase);
	/*for (i = 0; i < testCase; i++) {
		fscanf_s(fp, "%d", number);
		printf("%d\n", number, sizeof(int) * 3);
	}*/
	return 0;
}