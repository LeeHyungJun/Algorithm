#include <stdio.h>

//�縰��� �Լ��Դϴ�.
//recursion���� �����մϴ�.
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
		// 2���� 64�������� ��� �˻��մϴ�.
		for (j = 2; j <= 64; j++) {
			int arr[1000] = { 0 };
			i = 0;
			smallResult = number;
			//�ش� j������ ��ȯ�ϸ鼭 arr�迭�� �������� �����մϴ�.
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
			//������� arr�迭�� ����� 0 ~ i-1 �����Դϴ�.

			//����� �Ǵ� �κ��Դϴ�.
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