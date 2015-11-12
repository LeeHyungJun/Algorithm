#include <stdio.h>

int main() {
	int testCase,t, i, j, n,c_value,diagonal,k,tmp,p;
	FILE * fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &testCase);
	for (t = 0; t < testCase; t++) {
		fscanf(fp, "%d", &n);
		//cArr[] �� é�͸� ǥ���ϴ� �迭�Դϴ�.
		int cArr[501];
		//mArr[i][j]�� Ci���� Cj���� �� ����� �� �� �ּ� ���Դϴ�.
		int mArr[501][501];
		//cArr �ʱ�ȭ
		for (i = 1; i < n+1; i++) {
			fscanf(fp, "%d", &c_value);
			cArr[i] = c_value;
		}
		// i = j �ϰ��, mArr ���� 0.
		for (i = 1; i <= n; i++)
				mArr[i][i] = 0;
		//diagonal�� (1 ~ n-1 ) ���� ����ǰ� �밢���������� �迭�� ä������ �˴ϴ�.
		for (diagonal = 1; diagonal <= n-1; diagonal++) {
			for (i =1 ; i <= n - diagonal; i++) {
				//i�� j�� �밢���������� �����մϴ�.
				//ex) m[1][2] , m[2][3] , m [3][4].....
				j = i + diagonal;	
				//k�� ���ϴ� �Լ�. �ּ� mArr[i][j]�� ���մϴ�.
				for (k = i; k <= j - 1; k++) {
					tmp = mArr[i][k] + mArr[k + 1][j];
					if (k == i)
						mArr[i][j] = tmp;
					else if (mArr[i][j] >= tmp) {
						mArr[i][j] = tmp;
					}
				}//�� ������ ������ mArr[i][j]�� �ּҰ��� �� �����Դϴ�.
				for (p = i; p <= j; p++)
					mArr[i][j] = mArr[i][j] + cArr[p];	
			}
		}
		//mArr ���̺��� ���� ��� ����, i���� n������ é�͸� ���ϴ� �ּ��� ��� �Դϴ�.
		printf("%d\n", mArr[1][n]);
	}

	return 0;
}