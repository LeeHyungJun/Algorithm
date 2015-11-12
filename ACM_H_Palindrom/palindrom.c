#include <stdio.h>

//펠린드롬 함수입니다.
//recursion으로 구현합니다.
int palindrom(int *arr, int low, int high) {
	if (low >= high)
		return 1;
	else {
		if (arr[low] == arr[high])
			return palindrom(arr, low + 1, high - 1);
		else
			return 0;
	}
}

int main() {
	int t,i, j, k,tmp,n,remain,smallResult, testCase,number;
	FILE * fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &testCase);
	for (t = 0; t < testCase; t++) {
		fscanf(fp, "%d", &number);
		// 2부터 64진수까지 모두 검사합니다.
		for (j = 2; j <= 64; j++) {
			int arr[1000] = { 0 };
			i = 0;
			smallResult = number;
			//해당 j진수로 변환하면서 arr배열에 차례차례 대입합니다.
			for (;;) {
				if (smallResult < j) {
					arr[i++] = smallResult;	//reverse save.
					break;
				}
				else {
					arr[i++] = smallResult%j;
					smallResult = smallResult / j;
				}
			}
			// arrsize = i  // 0 ~ i-1
			//만들어진 arr배열은 사이즈가 0 ~ i-1 까지입니다.

			//출력이 되는 부분입니다.
			if (palindrom(arr, 0, i - 1)==1) {
				printf("1\n");
				break;
			}
			if (j == 64)
				printf("0\n");
		}
	}
	return 0;
}