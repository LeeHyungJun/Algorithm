#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int testCase,num,p=0;
	int triangleNumArr[45];
	int result[1001] = {0};
	fstream instream("input.txt", ios::in);
	instream >> testCase;



	for (int a = 1; a < 45; a++) {
		triangleNumArr[a] = a*(a + 1) / 2;
	}
	for (int i = 1; i < 45; i++) {
		for (int j = i; j < 45; j++) {
			for (int k = j; k < 45; k++) {
				if (triangleNumArr[i] + triangleNumArr[j] + triangleNumArr[k] < 1001)
					result[triangleNumArr[i] + triangleNumArr[j] + triangleNumArr[k]] = 1;
			}
		}
	}



	for (int q = 0; q < testCase; q++)
	{
		int count = 0;
		instream >> num;
		
		if (result[num] == 0)
			cout << "0" << endl;
		else if (result[num] == 1)
			cout << "1" << endl;
	}

}
		