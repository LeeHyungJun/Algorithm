#include <stdio.h>

int main() {
	int i, j, k,testCase,number;
	FILE * fp = fopen_s(file,"input.txt", "r");
	fscanf_s(fp, "%d", testCase);
	for (i = 0; i < testCase; i++) {
		fscanf_s(fp, "%d", number);
		printf("%d\n", number);
	}
	return 0;
}