/**************************
��ǻ�Ͱ��к� 20113315 ������
*****************************/
#include<iostream>
#include<fstream>

using namespace std;

//Using recursive function
int fibonacci(int n) {
	//base Case
	if (n == 0)
		return 0;
	else if (n==1)
		return 1;
	//recursive step
	else
		return fibonacci(n-1)+ fibonacci(n - 2);
}


int main()
{
	int testCase, num = 0;
	fstream instream("input.txt", ios::in);
	instream >> testCase;
	//testCase 
	for (int q = 0; q < testCase; q++)
	{
		instream >> num;
		//print out
		cout << fibonacci(num) << endl;
	}
}

