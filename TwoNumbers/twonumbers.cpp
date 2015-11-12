/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<cstring>

#define N_MAX 1000000

using namespace std;

//for qsort
int cmpfunc(const void * a, const void * b) { return (*(int*)a - *(int*)b); }

int twonumber(int *arr,int n, int k) {

	//left , right is index. front = left, right=rear
	int left=0, right=(n-1);
	//sum of two numbers.
	int sum;
	//num's count nearest to K.
	int count=0;
	int temp=1000000000;
	//multi access
	while (1) {
		if (left >= right)
			break;
		else {
			sum = arr[left] + arr[right];

			// move the index.
			if (k < sum)
				right--;
			else if (k >= sum)
				left++;
			////////////////////////////////////////

			//find num nearst to K
			//if u find new sum near than old sum to k , u have to initialization about k, and counting.
			if (abs(k - temp) > abs(k - sum)) {
				count = 0;
				count++;
				temp = sum;
			}
			//if K equal new sum, counting.
			else if (abs(k - temp) == abs(k - sum))
				count++;
		}
	}
	return count;
}

int main()
{
	int testCase, n,k;
	int arr[N_MAX];
	int count;
	fstream instream("input.txt", ios::in);
	instream >> testCase;
	for (int q = 0; q < testCase; q++)
	{
		count = 0;
		instream >> n >> k;
		for (int i = 0; i < n; i++)
			instream >> arr[i];
		qsort(arr, n, sizeof(int), cmpfunc);

		count = twonumber(arr,n,k);
		cout << count << endl;
	}
}
