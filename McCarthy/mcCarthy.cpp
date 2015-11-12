/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

//Using recursive function..John McCarthy
int mcCarthy(int num) {
	//base Case
	if ( num > 100)
		return num-10;
	//recursive step.
	else
		return mcCarthy(mcCarthy(num+11));

}


int main()
{
	int testCase, num, a, b = 0;
	fstream instream("input.txt", ios::in);
	instream >> testCase;
	//testCase 
	for (int q = 0; q < testCase; q++)
	{
		instream >> num;
		//print out
		cout << mcCarthy(num) << endl;
	}
}

