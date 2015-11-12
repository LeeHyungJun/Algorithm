/****************************************************
*
* Computer science department.
* Kookmin UNIV.
* Seoul ,South Korea.
* 20113315 ������, Harry HyeongJun Lee.
*
* gudwns05@kookmin.ac.kr
*
****************************************************/

#include <stdio.h>
#define MAX 100000

///////////
//
//	����ü qsort�� �̿��ؼ� ������Ǳ�ϴ�.
//	1. x�� �������� �������� ����
//	2. ��ŸƮ ����Ʈ�� ����ؼ� Ư�� �б⹮���� ���� y�� ��������/�������� ����
//
///////////


int tmp;
struct cafe{
	int x;
	int y;
};
//x���� ��������
int compareX(const void *A, const void  *B) {

	struct cafe* ptrA = (struct cafe*)A;
	struct cafe* ptrB = (struct cafe*)B;

	if (ptrA->x < ptrB->x) {
		return -1;
	}
	else if (ptrA->x == ptrB->x) {
		return 0;
	}
	else {
		return 1;
	}
}
//y���� ��������
int compareY2(const void *A, const void  *B) {

	struct cafe* ptrA = (struct cafe*)A;
	struct cafe* ptrB = (struct cafe*)B;


	if (ptrA->y > ptrB->y) {
		return -1;
	}
	else if (ptrA->y == ptrB->y) {
		return 0;
	}
	else {
		return 1;
	}
}
//y���� ��������
int compareY1(const void *A, const void  *B) {

	struct cafe* ptrA = (struct cafe*)A;
	struct cafe* ptrB = (struct cafe*)B;

	if (ptrA->y < ptrB->y) {
		return -1;
	}
	else if (ptrA->y == ptrB->y) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int testCase;
	int i,j,k,n,m,x,y,mm,cnt,a ;
	int ascending;
	int descending;
	FILE *fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &testCase);

	for (j = 0; j < testCase; j++) {
		cnt = 0;
		ascending=0;
		descending = 0;

		fscanf(fp, "%d", &n);
		struct cafe *arr;
		//y�� �������� ������ ���� ������.
		struct cafe *startPtr;
		//struct cafe ����ü�迭
		arr = (struct cafe*)malloc(sizeof(struct cafe)*(n+1));
		//�迭 �ʱ�ȭ
		for (i = 0; i < n; i++) {
			fscanf(fp, "%d %d", &x, &y);
			arr[i].x = x;
			arr[i].y = y;
		}
		//�� ������ ���� ����.
		arr[n].x = 100003;
		arr[n].y = 100003;
		//struct cafe arr[n]�� x���� �������� ����
		qsort(arr, n, sizeof(struct cafe), compareX);

		cnt = 1;
		//0���� n���� ���鼭 ������ �����մϴ�.
		for (i = 0; i < n; i++) {
			//���� ���� cafe�� x�� �ϳ� �� ũ�ٸ�
			if (arr[i].x < arr[i + 1].x) {
				//cnt==1 �� ó���϶�, ���� ���� �������ݴϴ�.
				if(cnt==1)
					tmp = arr[i].y;
				//Ȥ�� ó���� �ƴ϶�� �������� Ȥ�� ���������� �����մϴ�.
				else {
					//�������� �϶�.
					if (ascending == 1) {
						//printf("%d\n", cnt);
						qsort(startPtr, cnt, sizeof(struct cafe), compareY1);
						cnt = 1;
						//tmp�� �ʱ�ȭ
						tmp = arr[i].y;
						ascending = 0;
					}
					//�������� �϶�
					else if (descending == 1) {
						//printf("%d\n", cnt);
						qsort(startPtr, cnt, sizeof(struct cafe), compareY2);
						cnt = 1;
						//tmp�� �ʱ�ȭ
						tmp = arr[i].y;
						descending = 0;
					}
				}
			}
			// ���� �� ������ x���� ���� ������ x���� ���ٸ�
			 else if (arr[i].x == arr[i + 1].x) {
				 //ó���̶��
				if (cnt == 1) {
					if (tmp > arr[i].y) {
						startPtr = arr+i;
						descending = 1;
						//������� ������ �������� ����.
						cnt++;
					}
					else if (tmp < arr[i].y) {
						startPtr = arr+i;
						ascending = 1;
						cnt++;
						//���⼭���� ������ �������� ����.
					}
				}
				//ó���� �ƴ϶��
				else
					cnt++;
			}
		} //for (i = 0; i < n-1; i++)
		//����� �����ϱ����ؼ�  m�� �޾ƿɴϴ�.
		fscanf(fp, "%d", &m);
		//m�� ���鼭 Ǯ����� ������ �Է¹޴´�.
		for (k = 0; k < m; k++) {
			fscanf(fp, "%d", &mm);
			//�ذ�
			printf("%d %d\n", arr[mm - 1].x, arr[mm - 1].y);
		}
		//�����Ҵ� ����
		free(arr);

	} // testcase
	
	return 0;
}