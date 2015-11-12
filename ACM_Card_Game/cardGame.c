/*20113315 이형준*/
#include <stdio.h>

int main() {
	int testCase, t, i, j, n, c_value, diagonal, k, tmp, p, q;
	FILE * fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &testCase);
	for (t = 0; t < testCase; t++) {
		fscanf(fp, "%d", &n);
		//card 배열은 각 카드의 숫자를 표현하는 배열입니다.
		int card[1001];
		int sum[1001][1001] = {0};
		//mArr[i][j]은 card배열의 i부터 j까지의 합 중 엘리스가 뽑을 수 있는 최대값을 뜻함.
		int mArr[1001][1001] = {0};
		//card배열 초기화
		for (i = 1; i < n + 1; i++) {
			fscanf(fp, "%d", &c_value);
			card[i] = c_value;
		}
		// i = j 일경우, mArr[i][j]=card[i].
		//sum 배열도 같이 초기화.
		for (i = 1; i <= n; i++) {
			mArr[i][i] = card[i];
			sum[i][i] = card[i];
		}
		//diagonal은 (1 ~ n-1 ) 까지 진행되고 대각선방향으로 배열이 채워지게 됩니다.
		for (diagonal = 1; diagonal <= n - 1; diagonal++) {
			for (i = 1; i <= n - diagonal; i++) {
				//i와 j가 대각선방향으로 증가합니다.
				//ex) m[1][2] , m[2][3] , m [3][4].....
				j = i + diagonal;
				//sum배열또한 bottom up방식으로 설정해줍니다.
				sum[i][j] = sum[i][i] + sum[i + 1][j];
				//일반식은 다음과 같습니다.
				//mArr[i][j]=sum[i][j]-min(m[i][j-1], m[i+1][j])
				if (mArr[i][j - 1] > mArr[i + 1][j])
					mArr[i][j] = sum[i][j] - mArr[i + 1][j];
				else
					mArr[i][j] = sum[i][j] - mArr[i][j - 1];
			}
		}
		//출력
		printf("%d\n", mArr[1][n]);

	}

	return 0;
}