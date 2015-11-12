/****************************************************
*
* Algorithm class
* Computer science department.
* Kookmin UNIV.
* Seoul ,South Korea.
* 20113315 이형준, Harry HyungJun Lee.
*
* gudwns05@kookmin.ac.kr
*
****************************************************/

// Developed in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*// O(n3)
int maxSubsequenceSum(int a[], int n)
{
	int i, j, k;
	int maxSum = 0;
	//*start = *end = -1;
	for (i = 0; i<n; i++)
		for (j = i; j<n; j++)
		{
			int thisSum = 0;
			for (k = i; k <= j; k++)
				thisSum += a[k];
			if (thisSum > maxSum)
			{
				maxSum = thisSum;
				//*start = i;	//start index.
				//*end = j;	//end index.
			}
		}
	return maxSum;
}
*/
	/*//O(n2)
int maxSubsequenceSum(int a[], int n)
{
	int i, j, k;
	int maxSum = 0;
	for (i = 0; i<n; i++)
	{
		int thisSum = 0;
		for (j = i; j<n; j++)
		{
			thisSum += a[j];
			if (thisSum > maxSum)
			{
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}*/
/* //O(n)
int maxSubsequenceSum (int a[], int n)
{
	
	int i, j;
	int maxSum = 0, thisSum = 0;
	for(i=0, j=0; j<n; j++)
	{
		
		thisSum += a[j];
		if(thisSum > maxSum)
		{
			maxSum = thisSum;
		}
		else if(thisSum < 0)
		{
			i = j+1;
			thisSum = 0;
		}
	}
	return maxSum;
}
*/

unsigned long long cnt = 0;

int combine(int a[], int n, int low, int mid, int high) {
	int i, j,leftThisSum=0, leftMaxSum=a[mid];
	int rightThisSum = 0, rightMaxSum = a[mid+1];
	int result;
	for (i = mid, j = mid; j >= low; j--) {
		cnt++;
		leftThisSum = leftThisSum + a[j];
		if (leftThisSum > leftMaxSum)
			leftMaxSum = leftThisSum;
	}

	for (i = mid+1, j = mid+1; j <= high; j++) {
		cnt++;
		rightThisSum = rightThisSum + a[j];
		if (rightThisSum > rightMaxSum)
			rightMaxSum = rightThisSum;
	}
	result = leftMaxSum + rightMaxSum;
	return result;
}
int maxOfthreePart(int a, int b, int c) {
	int max;
	if (a > b)
		max = a;
	else
		max = b;
	if (c > max)
		max = c;
	return max;
}
int maxSubsequenceSum(int a[], int n,int low,int high)
{
	cnt++;
	int i, j, mid, max,leftMax,rightMax, middleMax;
	if (low == high) 
		return a[low];
	mid = (low + high) / 2;
	leftMax = maxSubsequenceSum(a,n,low,mid);
	rightMax = maxSubsequenceSum(a,n,mid+1,high);
	middleMax = combine(a, n, low, mid, high);
	return maxOfthreePart(leftMax, rightMax, middleMax);
}

int main() {

	FILE *fp = fopen("testdata.txt","r");
	time_t start_time, finish_time;
	int testCount=0;
	int a,i,result;
	int *arr;
	long startTime,finishTime;

	arr = (int*)malloc(sizeof(int) * 1000000);
	fscanf(fp, "%d", &testCount);
	testCount = 100000;
	for (i = 0; i < testCount; i++) {
		fscanf(fp, "%d", &a);
		arr[i] = a;
	}

	startTime = time(&start_time);
//	result =maxSubsequenceSum(arr, testCount);
	result = maxSubsequenceSum(arr, testCount, 0, testCount - 1);
	//printf("%d\n", result);
	finishTime = time(&finish_time);
	printf("걸린시간 : %ld\n", finishTime - startTime);
	printf("%I64u", cnt);
	return 0;
}