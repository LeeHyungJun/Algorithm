#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main()
{
	int testCase,h,w,n;
	fstream instream("input.txt", ios::in);
	instream >> testCase;

	for (int i = 0; i<testCase; i++)
	{
		int count = 0;
		instream >> h;
		instream >> w;
		instream >> n;

		for (int j = 1; j <= w; j++) {
			for (int k = 1; k <= h; k++) {
				count++;
				if (count == n) {
					if(j<10)
						cout << k << "0"<< j<<endl;
					else
						cout << k << j << endl;
				}
			}
		}
	}

	return 0;
}