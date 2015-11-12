/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<fstream>
#include <cstring>

using namespace std;

int Fac(int num) {
	if (num == 0)	return 1;			
	else return num * Fac(num - 1); 
}

void push(char *a, char *b) {
	*a = *b;
}

void matching(int *arr, int amount) {
	char str[] = "abcdefghijkl";
	int i, j, k;

	for (i = 0; i<amount; i++) {
		printf("%c", str[arr[i]]);
		k = arr[i];
		for (j = i; j<amount; j++) {
			push(&str[k], &str[k + 1]); 
			if (++k>12) break;
		}
	}
	printf("\n");
}

void Permutation(int amount, int seq) {
	int num = amount, i;
	int arr[12] = { 0 };

	
	//1 + ∑{(n-k)! * a(k)}
	for (i = 0; i<amount; i++) {
		arr[i] = seq / Fac(--num);
		seq = seq%Fac(num);
	}
	matching(arr, amount);
}

int main() {
	int cases, amount, seq, i;

	FILE *infile = fopen("input.txt", "r");
	fscanf(infile, "%d", &cases);

	for (i = 0; i<cases; i++) {
		fscanf(infile, "%d %d", &amount, &seq);
		Permutation(amount, seq - 1);
	}
	fclose(infile);
	return 0;
}