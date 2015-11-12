/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<fstream>

using namespace std;

//Using recursive function
int palindrome(char arr[], int first , int last) {
	//base Case.  if you end to do compare and remain one char , you get return 1.
	if (last <= first)
		return 1;
	// if same value of arr[first] with value of arr[last], you call recursive. 
	else if (arr[first] == arr[last])
		return palindrome(arr, first + 1, last - 1);
	// not same case. arr[first] =! arr[last]
	else
		return 0;
}

void main(void)
{
	int testCase, num = 0;
	char str[1001];
	fstream instream("input.txt", ios::in);
	instream >> testCase;
	//testCase 
	for (int q = 0; q < testCase; q++)
	{
		instream >> str;
		cout << str << endl;
		cout << palindrome(str,0,strlen(str)-1) << endl;
	}
}

