
/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<fstream>

using namespace std;

//Using recursive function
int fac(int n) {
	//base Case
	if (n <= 1)
		return n;
	//recursive step
	else
		return n*fac(n - 1);
}


int main()
{
	int testCase,num= 0;
	fstream instream("input.txt", ios::in);
	instream >> testCase;
	//testCase 
	for (int q = 0; q < testCase; q++)
	{
		instream >> num;
		//print out
		cout << fac(num) << endl;
	}
}

