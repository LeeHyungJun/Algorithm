/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

#define MAX_SIZE 50
char inputString[MAX_SIZE];

//  ')' = '-'  and '(' = '+'.
//  So, totalBalanceCount means that sum of '(' and ')'
//  if totalBalanceCount < 0  means that ')' count bigger than '(' count.
int totalBalanceCount;
// n means that index.
int n;

// return 0 means that No
// return 1 means that YES

int parenthesis(char *inputString, int length) {
	// ')'  >  '('
	// ')' count bigger than '(' count.
	if (totalBalanceCount < 0)
		return 0;
	// if index is end of Array, you have to check totalBal. 
	else if (n == length && totalBalanceCount > 0)
		return 0;
	// if enter char '(', you plus totalBalanceCount 
	if (inputString[n] == '(') {
		totalBalanceCount++;
		// n means index.
		n++;
		// recursive step.
		parenthesis(inputString, length);
	}
	// if enter char ')', you minus totalBalanceCount 
	else if (inputString[n] == ')') {
		totalBalanceCount--;
		n++;
		// recursive step.
		parenthesis(inputString, length);
	}
	// if you end of array length, you must check totalBalanceCount. 
	else if(n == length){
		if (totalBalanceCount > 0)
			return 0;					//no
		else if (totalBalanceCount == 0)
			return 1;					//yes
		else
			return 0;					//no
	}
}


int  main() {
	int result = 0;
	char testCase[2];
	int testcase;
	ifstream inFile("input.txt");

	inFile.getline(testCase, 2);
	testcase = testCase[0]-'0';
	
	for (int i = 0; i < testcase; i++) {
		totalBalanceCount = 0;
		n = 0;
		// read line.
		inFile.getline(inputString, MAX_SIZE);
		// result is 0 or 1.
		result = parenthesis(inputString, strlen(inputString));
		
		if (result == 1)
			cout << "YES" << endl;
		else if (result == 0)
			cout << "NO" << endl;
		else
			cout << "ERROR" << endl;
	}
	
	inFile.close();
	return 0;

}
