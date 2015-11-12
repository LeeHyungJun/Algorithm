#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int prime(int num)
{
	int count;
		for (int i = 2; i <= sqrt(num); i++) {		// Cause time problem.
			if (num%i == 0)
				count++;
		}
		if (count > 0)
			return 0; // not prime
		else
			return 1; // prime
		
}

int main() 
{
	int testCase,cnt=2;
	int primeArr[1000];
	fstream instream("input.txt", ios::in);
	instream >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int num;
		instream >> num;
		primeArr[0] = 2;
		primeArr[1] = 3;
		for (int j = 4; j < num; j++) {
			//소수면 배열에 순서대로저장한다.
			if(prime(j)==1)
				primeArr[cnt++]=j;
		}

		for (int k = 0; k < cnt; k++) {
			cout << primeArr[k];
		}
		cout << endl;
	}


}