/**************************
��ǻ�Ͱ��к� 20113315 ������
*****************************/
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
using namespace std;

//This function calculate prime number. 
int prime(int num)
{
	int count=0;
	for (int i = 2; i <= sqrt(num); i++) {		// Cause time problem.
		if (num%i == 0)
			count++;
	}
	if (count > 0)
		return 0; // not prime
	else
		return 1; // prime
}
// Is Two prime num equaled with original number?
void sameCompare(int originNum,int *primeArr, int arrLen)
{
	int a = 0;
	int tempArr1[1000];
	int tempArr2[1000];

	// All case.
	for (int i = 0; i < arrLen; i++)
	{
		for (int j = i; j < arrLen; j++) 
		{
			if (originNum == primeArr[i] + primeArr[j])
			{
				//tempArr1 means first prime number.
				tempArr1[a] = primeArr[i];
				//tempArr2 means 2nd prime number.
				tempArr2[a++] = primeArr[j];
			}
		}
	}
	//differ means that <1 prime - 2 prime>
	int differ[1000];
	int l,index;
	for (l = 0; l <a; l++) {
		// I will fimd value that small difference into two prime number
		differ[l] = abs(tempArr1[l] - tempArr2[l]);
	}
	// I will found smallest differ
	int smallest = differ[0];
	for (int i = 0; i <= l - 1; i++)
	{
		if (differ[i] <= smallest && i != l - 1)
		{
			smallest = differ[i];

		}
		else if (differ[i] <= smallest && i == l - 1)
		{
			smallest = differ[i];
			cout << tempArr1[i] <<" "<< tempArr2[i];
		}
	}
	// initialize.
	l = 0;
}

int main()
{
	int testCase;
	int primeArr[1000];
	fstream instream("input.txt", ios::in);
	instream >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		for (int k = 0; k < 1000; k++)
			primeArr[k] = 0;

		int num,cnt=2;
		instream >> num;
		primeArr[0] = 2;
		primeArr[1] = 3;
		for (int j = 4; j < num; j++) {
			//IF return result is primenumber, you save. 
			if (prime(j) == 1)
				primeArr[cnt++] = j;
		}

		sameCompare(num, primeArr, cnt);
		cout << endl;
	}


}
