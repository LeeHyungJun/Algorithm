#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE
#define MAX 1000000

int main() {
	int cases, i, j, set, target;
	int arr[MAX];
	FILE *fin;
	fopen_s(&fin,"input.txt", "r");
	fscanf_s(fin, "%d", &cases);

	for (i = 0; i<cases; i++) {
		fscanf_s(fin, "%d %d", &set, &target);
		for (j = 0; j<set; j++)
			fscanf_s(fin, "%d", &arr[j]);
		for (j = 0; j<set; j++)
			printf("%d ", arr[j]);
		printf("\n");
	}
	fclose(fin);
}