/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

// matching.
void change(char *a, char *b) {
	*a = *b;
}
// this func process certain order of string controling.
void 
processing(int *arr, int sig) {
	// para sig means that amount.
	int index_a;
	char strArr[] = "abcdefghijkl";

	for (int i = 0; i<sig; i++) {
		cout << strArr[arr[i]];
		index_a = arr[i];
		for (int j = i; j<sig; j++) {
			change(&strArr[index_a], &strArr[index_a + 1]);
			index_a++;
			if (index_a>12)
				break;
		}
	}
	cout << endl;
}
// this func is comutataion factorial.
int Fac(int num) {
	if (num == 0)
		return 1;
	else
		return num * Fac(num - 1);
}


void Permutation(int sig, int seq) {
	int num = sig;
	int arr[12] = {0};

	//1 + ∑{(n-k)! * a(k)} .. you can do that! revese!
	for (int i = 0; i<sig; i++) {
		arr[i] = seq / Fac(--num);
		seq = seq%Fac(num);
	}
	processing(arr, sig);
}

int main() {
	int cases, amount, seq, i;

	fstream instream("input.txt", ios::in);
	instream >> cases;

	for (i = 0; i<cases; i++) {
		instream >> amount >> seq;
		// formual about permutation is 1 + ∑{(n-k)! * a(k)}.
		// so, I will revese this formual
		Permutation(amount, seq - 1);
	}
	return 0;
}