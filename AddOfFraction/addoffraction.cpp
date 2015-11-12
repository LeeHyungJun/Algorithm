/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

//func GCD.... using recursive function
int gcd(int a, int b) {
	//base Case
	if (b == 0)
		return a;
	//recursive step.
	//Euclid’s algorithm
	else
		return gcd(b, a%b);
}

int main()
{
	int testCase, result_chid , result_pare, a, b, c, d = 0;
	fstream instream("input.txt", ios::in);
	instream >> testCase;
	//testCase
	for (int q = 0; q < testCase; q++)
	{
		instream >> a >> b >> c >> d;
		//Add of fraction
		result_chid = (a*d) + (c*b);
		result_pare = (d*b);
		//division of fraction
		cout << result_chid/(gcd(result_chid, result_pare)) <<" "<< result_pare/ (gcd(result_chid, result_pare)) << endl;
	}
}

