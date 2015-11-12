/****************************************************
*
* Computer science department.
* Kookmin UNIV.
* Seoul ,South Korea.
* 20113315 이형준, Harry HyeongJun Lee.
*
* gudwns05@kookmin.ac.kr
*
****************************************************/

#include <stdio.h>
#define MAX 100000

///////////
//
//	구조체 qsort를 이용해서 문제를풉니다.
//	1. x를 기준으로 오름차순 소팅
//	2. 스타트 포인트를 기록해서 특정 분기문으로 인한 y축 오름차순/내림차순 소팅
//
///////////


int tmp;
struct cafe{
	int x;
	int y;
};
//x기준 오름차순
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
//y기준 내림차순
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
//y기준 오름차순
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
		//y를 기준으로 소팅할 시작 기준점.
		struct cafe *startPtr;
		//struct cafe 구조체배열
		arr = (struct cafe*)malloc(sizeof(struct cafe)*(n+1));
		//배열 초기화
		for (i = 0; i < n; i++) {
			fscanf(fp, "%d %d", &x, &y);
			arr[i].x = x;
			arr[i].y = y;
		}
		//맨 마지막 숫자 지정.
		arr[n].x = 100003;
		arr[n].y = 100003;
		//struct cafe arr[n]을 x기준 오름차순 소팅
		qsort(arr, n, sizeof(struct cafe), compareX);

		cnt = 1;
		//0부터 n까지 돌면서 소팅을 진행합니다.
		for (i = 0; i < n; i++) {
			//만약 다음 cafe가 x가 하나 더 크다면
			if (arr[i].x < arr[i + 1].x) {
				//cnt==1 즉 처음일때, 비교할 값을 저장해줍니다.
				if(cnt==1)
					tmp = arr[i].y;
				//혹시 처음이 아니라면 오름차순 혹은 내림차순을 진행합니다.
				else {
					//오름차순 일때.
					if (ascending == 1) {
						//printf("%d\n", cnt);
						qsort(startPtr, cnt, sizeof(struct cafe), compareY1);
						cnt = 1;
						//tmp값 초기화
						tmp = arr[i].y;
						ascending = 0;
					}
					//내림차순 일때
					else if (descending == 1) {
						//printf("%d\n", cnt);
						qsort(startPtr, cnt, sizeof(struct cafe), compareY2);
						cnt = 1;
						//tmp값 초기화
						tmp = arr[i].y;
						descending = 0;
					}
				}
			}
			// 만약 내 까페의 x값과 다음 까페의 x값이 같다면
			 else if (arr[i].x == arr[i + 1].x) {
				 //처음이라면
				if (cnt == 1) {
					if (tmp > arr[i].y) {
						startPtr = arr+i;
						descending = 1;
						//여기부터 끝까지 내림차순 소팅.
						cnt++;
					}
					else if (tmp < arr[i].y) {
						startPtr = arr+i;
						ascending = 1;
						cnt++;
						//여기서부터 끝까지 오름차순 소팅.
					}
				}
				//처음이 아니라면
				else
					cnt++;
			}
		} //for (i = 0; i < n-1; i++)
		//결론을 도출하기위해서  m을 받아옵니다.
		fscanf(fp, "%d", &m);
		//m번 돌면서 풀어야할 문제를 입력받는다.
		for (k = 0; k < m; k++) {
			fscanf(fp, "%d", &mm);
			//해결
			printf("%d %d\n", arr[mm - 1].x, arr[mm - 1].y);
		}
		//동적할당 프리
		free(arr);

	} // testcase
	
	return 0;
}