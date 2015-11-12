/*20113315 ������*/
#include <stdio.h>

int main() {
	int testCase, t, i, j, n, c_value, diagonal, k, tmp, p, q;
	FILE * fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &testCase);
	for (t = 0; t < testCase; t++) {
		fscanf(fp, "%d", &n);
		//card �迭�� �� ī���� ���ڸ� ǥ���ϴ� �迭�Դϴ�.
		int card[1001];
		int sum[1001][1001] = {0};
		//mArr[i][j]�� card�迭�� i���� j������ �� �� �������� ���� �� �ִ� �ִ밪�� ����.
		int mArr[1001][1001] = {0};
		//card�迭 �ʱ�ȭ
		for (i = 1; i < n + 1; i++) {
			fscanf(fp, "%d", &c_value);
			card[i] = c_value;
		}
		// i = j �ϰ��, mArr[i][j]=card[i].
		//sum �迭�� ���� �ʱ�ȭ.
		for (i = 1; i <= n; i++) {
			mArr[i][i] = card[i];
			sum[i][i] = card[i];
		}
		//diagonal�� (1 ~ n-1 ) ���� ����ǰ� �밢���������� �迭�� ä������ �˴ϴ�.
		for (diagonal = 1; diagonal <= n - 1; diagonal++) {
			for (i = 1; i <= n - diagonal; i++) {
				//i�� j�� �밢���������� �����մϴ�.
				//ex) m[1][2] , m[2][3] , m [3][4].....
				j = i + diagonal;
				//sum�迭���� bottom up������� �������ݴϴ�.
				sum[i][j] = sum[i][i] + sum[i + 1][j];
				//�Ϲݽ��� ������ �����ϴ�.
				//mArr[i][j]=sum[i][j]-min(m[i][j-1], m[i+1][j])
				if (mArr[i][j - 1] > mArr[i + 1][j])
					mArr[i][j] = sum[i][j] - mArr[i + 1][j];
				else
					mArr[i][j] = sum[i][j] - mArr[i][j - 1];
			}
		}
		//���
		printf("%d\n", mArr[1][n]);

	}

	return 0;
}