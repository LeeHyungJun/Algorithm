#include <stdio.h>

int main() {
	int testCase,t, i, j, n,c_value,diagonal,k,tmp,p;
	FILE * fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &testCase);
	for (t = 0; t < testCase; t++) {
		fscanf(fp, "%d", &n);
		//cArr[] 은 챕터를 표현하는 배열입니다.
		int cArr[501];
		//mArr[i][j]은 Ci부터 Cj까지 의 비용의 합 중 최소 값입니다.
		int mArr[501][501];
		//cArr 초기화
		for (i = 1; i < n+1; i++) {
			fscanf(fp, "%d", &c_value);
			cArr[i] = c_value;
		}
		// i = j 일경우, mArr 값은 0.
		for (i = 1; i <= n; i++)
				mArr[i][i] = 0;
		//diagonal은 (1 ~ n-1 ) 까지 진행되고 대각선방향으로 배열이 채워지게 됩니다.
		for (diagonal = 1; diagonal <= n-1; diagonal++) {
			for (i =1 ; i <= n - diagonal; i++) {
				//i와 j가 대각선방향으로 증가합니다.
				//ex) m[1][2] , m[2][3] , m [3][4].....
				j = i + diagonal;	
				//k를 구하는 함수. 최소 mArr[i][j]를 구합니다.
				for (k = i; k <= j - 1; k++) {
					tmp = mArr[i][k] + mArr[k + 1][j];
					if (k == i)
						mArr[i][j] = tmp;
					else if (mArr[i][j] >= tmp) {
						mArr[i][j] = tmp;
					}
				}//이 포문을 지나면 mArr[i][j]는 최소값이 된 상태입니다.
				for (p = i; p <= j; p++)
					mArr[i][j] = mArr[i][j] + cArr[p];	
			}
		}
		//mArr 테이블의 좌측 상단 값이, i부터 n까지의 챕터를 합하는 최소의 비용 입니다.
		printf("%d\n", mArr[1][n]);
	}

	return 0;
}