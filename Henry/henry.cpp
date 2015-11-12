/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

int henry(int a, int b) {
	int i=0;
	// bace step. 
	// if reducible fraction number, you have to reduction.
	// At the end, if a equal 1 , return.
	if (b%a==0)
		return b/a;
	// Process find out "number i"
	// i means that 1/i <= a/b.
	// i is the largest number of fomular.
	for (int i = 1; i < 10000; i++) {
		// If you find i, "a/b - 1/i" = a/b.
		// Proccess recursive step.
		if (b <= a*i) {
			henry(((a*i) - b), (b*i));
			break;
		}
	}
}

int  main() {
	int result = 0;
	int a=0,b=0;
	int testCase;
	fstream instream("input.txt", ios::in);
	instream >> testCase;
	// testCase num
	for (int i = 0; i < testCase; i++)
	{
		// means that a/b
		instream >> a >> b;
		cout << henry(a, b) << endl;
	}

}
