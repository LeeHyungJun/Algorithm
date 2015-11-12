/****************************************************
*
* Algorithm class
* Computer science department.
* Kookmin UNIV.
* Seoul ,South Korea.
* 20113315 이형준, Harry HyungJun Lee.
*
* gudwns05@kookmin.ac.kr
*
****************************************************/
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;
#define MARK 1
#define UNMARK 0

typedef struct Point {
	int x;
	int y;
}point;

point direction[8] = { { 1, -2 },{ 2, -1 },{ 2, 1 },{ 1, 2 },
{ -1, 2 },{ -2, 1 },{ -2, -1 },{ -1, -2 } };

//OMRcard에는 해당 지점에 방문하였으면 MARK, 비방문이면 UNMARK를 합니다.
int OMRcard[9][9];
// 
int path[9][9];

int knightTour(int m, int n, point pos, int path_count) {
	
	point next;


	//path를 찾는데 성공한 것입니다.
	if (path_count == (m*n))
		return 1;


	//내 주변 8개의 방향을 탐지합니다.
	for (int i = 0; i < 8; i++)
	{	
		//방향을 차례차례 이동하여 봅니다.
		next.x = pos.x + direction[i].x;
		next.y = pos.y + direction[i].y;
		//벽에 닿지 않거나, 방문을 안 한 상태라면
		if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m && OMRcard[next.y][next.x] != MARK)
		{
			//omr 배열에 마크를 찍습니다.
			OMRcard[next.y][next.x] = MARK;
			//path 배열에 이 걸음이 몇번째 걸음인지 체크합니다.
			path[next.y][next.x] = path_count + 1;

			//recursive하게 호출합니다. 
			//끝까지 함수호출을 반복하다가 마지막 knightTour함수에서 리턴 1이된다면
			//count==m*n 인 상태이고, 길을 찾는데 성공한것입니다.
			//그 후로 호출되었던 모든 함수들은 1리턴을 반복합니다.
			if(knightTour(m, n, next, path_count + 1))
				return 1;
			else
				OMRcard[next.y][next.x] = UNMARK;  //이거 하나만안써도 출력 0 0 나
		}

		//만약 벽에 닿거나 방문을 이미 한 상태라면
		//for 문을 8번 돌면서 다음 방향을 모색합니다.
	}
	//만약 8방향 모두 갈 길을 잃었다면, 0이 리턴됩니다. 내가 있는 지점에서 길찾기를 실패한것입니다.
	// 0이 리턴딘다면 나의 함수를 호출했던 함수의 else부분으로 가서 내가 있었던자리를 UNMARK합니다.
	//그리고 다음 방향을 모색합니다.
	return 0;
}


int main()
{
	int testCase, m, n;
	fstream instream("input.txt", ios::in);
	instream >> testCase;
	for (int q = 0; q < testCase; q++)
	{
		point start;
		int path_count;
		//M행 * N열 
		instream >> m >> n;
		instream >> start.y >> start.x;
		//우
		for (int i = 1; i <=m; i++)
			for (int j = 1; j <=n; j++)
				OMRcard[i][j] = UNMARK;

		OMRcard[start.y][start.x] = MARK;
		path[start.y][start.x] = 1;

		if (knightTour(m, n, start, 1)) {
			cout << 1 << endl;
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {
					cout << path[i][j] << " ";
				}cout << endl;
			}
		}
		else
			cout << 0 << endl;
			
	}
	return 0;
}
