#include <stdio.h>
#include <string.h>

int main()
{
	int a, b, c, d,i,j,t,n,m,testCase;
	//plus[] 는 득점을 나타내는 배열이다
	int plus[1000];
	//sub[] 은 실점을 나타내는 배열이다.
	int sub[1000];
	float score[1000];
	int max,min,result;
	FILE * fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &testCase);

	for (t = 0; t < testCase; t++) {
		fscanf(fp, "%d %d", &n, &m);
		memset(plus, 0, 4000);
		memset(sub, 0, 4000);
		memset(score, 0, 4000);
		for (j = 1; j <= m; j++) {
			
			//input.txt에서 입력받을 때 일련의 작업을 거친다.
			// a팀의 득점을 plus[a]
			// a팀의 실점을 sub[a]
			// b팀의 득점을 plus[a]
			// b팀의 실점을 sub[a]
			fscanf(fp, "%d %d %d %d", &a, &b, &c, &d);
				plus[a] = plus[a] + c;
				sub[a] = sub[a] + d;
				plus[b] = plus[b] + d;
				sub[b] = sub[b] + c;
		}

		max = 0;
		min = 1000000;
		for (i = 1; i <= n; i++) {
			//피타고라스 기대값을 구하는 공식. w=s^2 / s^2 + A^2 
			result = (plus[i] * plus[i])*1000 /((plus[i] * plus[i]) + (sub[i] * sub[i]));
			//결과가 최대인것과 최소인것을 뽑아내서 출력합니다.
			if (result > max)
				max = result;
			if (result < min)
				min = result;			
		}
		printf("%d\n%d\n", max, min);
	}
    return 0;
}

