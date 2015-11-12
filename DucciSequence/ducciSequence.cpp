/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>

using namespace std;

// If you use variable called flag, you can distinguish whether "ZERO" or "Loop"
int flag;

void ducciSequence(int *ducciNumArr, int ducciNum) {

	int tempArr[1000];
	int zeroOfcnt = 0, cnt = 0;
	int a = 0;
	int num = 1000;

	flag = 3;
	// maximum value is 1000
	while (num--)
	{
		// I copied ducciNumArr.. tempArr is previous value of ducciNumArr .
		for (int j = 0; j < ducciNum; j++)
			tempArr[j] = ducciNumArr[j];

		// If All of duccinumArr's value is zero, printout 0.
		for (int j = 0; j < ducciNum; j++) {

			if (ducciNumArr[j] == 0) {
				zeroOfcnt++;
			}
		}
		if (zeroOfcnt == ducciNum) {
			flag = 0;	//zero
			break;
		}
		// initialize
		zeroOfcnt = 0;

		// duccinumArr[0] copy.
		int tempp = 0;
		tempp = ducciNumArr[0];

		// If All of duccinumArr's value is not zero, update ducciNumArr value.
		// a1,a2,?,an →( a1?a2 , a2?a3 ,?, an?a1 )
		for (int i = 0; i < ducciNum; i++)
		{
			if (i == (ducciNum - 1))
				ducciNumArr[i] = abs(ducciNumArr[i] - tempp);
			else
				ducciNumArr[i] = abs(ducciNumArr[i] - ducciNumArr[i + 1]);
		}

		// tempArr is previous Arr value. so,If same tempArr and ducciarr, printout 1. 
		for (int j = 0; j < ducciNum; j++) {
			if (ducciNumArr[j] == tempArr[j]) {
				cnt++;
			}
		}
		if (cnt == ducciNum) {
			flag = 1;		//Loop
			break;
		}
		cnt = 0;

		// If you reach whilenum at maximum 1000, regard "Loop" 
		if (num == 0) {
			flag = 1;	//Loop
			break;
		}
	}
}


int main() {
	int cases, amount, seq, ducciNum, n = 0;
	int ducciNumArr[15] = { 0 };

	fstream instream("input.txt", ios::in);
	instream >> cases;

	for (int i = 0; i < cases; i++) {
		instream >> ducciNum;

		for (int j = 0; j < ducciNum; j++)
			instream >> ducciNumArr[j];

		// main algorithm
		ducciSequence(ducciNumArr, ducciNum);

		// Because printout string.
		if (flag == 0)
			cout << "ZERO" << endl;
		if (flag == 1)
			cout << "LOOP" << endl;
	}
	return 0;
}