#include <stdio.h>
#include <string.h>

int main()
{
	int a, b, c, d,i,j,t,n,m,testCase;
	//plus[] �� ������ ��Ÿ���� �迭�̴�
	int plus[1000];
	//sub[] �� ������ ��Ÿ���� �迭�̴�.
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
			
			//input.txt���� �Է¹��� �� �Ϸ��� �۾��� ��ģ��.
			// a���� ������ plus[a]
			// a���� ������ sub[a]
			// b���� ������ plus[a]
			// b���� ������ sub[a]
			fscanf(fp, "%d %d %d %d", &a, &b, &c, &d);
				plus[a] = plus[a] + c;
				sub[a] = sub[a] + d;
				plus[b] = plus[b] + d;
				sub[b] = sub[b] + c;
		}

		max = 0;
		min = 1000000;
		for (i = 1; i <= n; i++) {
			//��Ÿ��� ��밪�� ���ϴ� ����. w=s^2 / s^2 + A^2 
			result = (plus[i] * plus[i])*1000 /((plus[i] * plus[i]) + (sub[i] * sub[i]));
			//����� �ִ��ΰͰ� �ּ��ΰ��� �̾Ƴ��� ����մϴ�.
			if (result > max)
				max = result;
			if (result < min)
				min = result;			
		}
		printf("%d\n%d\n", max, min);
	}
    return 0;
}

