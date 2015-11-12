/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;




void push(char *a, char *b) {
	*a = *b;
}

void matching(int *arr, int amount) {
	int k;
	char str[] = "abcdefghijkl";


	for (int i = 0; i<amount; i++) {
		cout << str[arr[i]];
		k = arr[i];
		for (int j = i; j<amount; j++) {
			push(&str[k], &str[k + 1]);
			k++;
			if (k>12)
				break;
		}
	}
	cout << endl;
}


int Fac(int num) {
	if (num == 0)
		return 1;
	else
		return num * Fac(num - 1);
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

	fstream instream("input.txt", ios::in);
	instream >> cases;

	for (i = 0; i<cases; i++) {
		instream >> amount >> seq;
		Permutation(amount, seq - 1);
	}
	return 0;
}