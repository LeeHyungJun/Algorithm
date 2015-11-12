/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

//Using recursive function
int gcd(int a, int b) {
	//base Case
	if (b == 0)
		return a;
	//recursive step.
	//Euclid’s algorithm
	else
		return gcd(b,a%b);
	
}


int main()
{
	int testCase, num,a,b = 0;
	fstream instream("input.txt", ios::in);
	instream >> testCase;
	//testCase 
	for (int q = 0; q < testCase; q++)
	{
		instream >> a;
		instream >> b;
		//print out
		cout << gcd(a,b) << endl;
	}
}

