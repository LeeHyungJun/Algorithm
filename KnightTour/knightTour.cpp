/****************************************************
*
* Algorithm class
* Computer science department.
* Kookmin UNIV.
* Seoul ,South Korea.
* 20113315 ������, Harry HyungJun Lee.
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

//OMRcard���� �ش� ������ �湮�Ͽ����� MARK, ��湮�̸� UNMARK�� �մϴ�.
int OMRcard[9][9];
// 
int path[9][9];

int knightTour(int m, int n, point pos, int path_count) {
	
	point next;


	//path�� ã�µ� ������ ���Դϴ�.
	if (path_count == (m*n))
		return 1;


	//�� �ֺ� 8���� ������ Ž���մϴ�.
	for (int i = 0; i < 8; i++)
	{	
		//������ �������� �̵��Ͽ� ���ϴ�.
		next.x = pos.x + direction[i].x;
		next.y = pos.y + direction[i].y;
		//���� ���� �ʰų�, �湮�� �� �� ���¶��
		if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m && OMRcard[next.y][next.x] != MARK)
		{
			//omr �迭�� ��ũ�� ����ϴ�.
			OMRcard[next.y][next.x] = MARK;
			//path �迭�� �� ������ ���° �������� üũ�մϴ�.
			path[next.y][next.x] = path_count + 1;

			//recursive�ϰ� ȣ���մϴ�. 
			//������ �Լ�ȣ���� �ݺ��ϴٰ� ������ knightTour�Լ����� ���� 1�̵ȴٸ�
			//count==m*n �� �����̰�, ���� ã�µ� �����Ѱ��Դϴ�.
			//�� �ķ� ȣ��Ǿ��� ��� �Լ����� 1������ �ݺ��մϴ�.
			if(knightTour(m, n, next, path_count + 1))
				return 1;
			else
				OMRcard[next.y][next.x] = UNMARK;  //�̰� �ϳ����Ƚᵵ ��� 0 0 ��
		}

		//���� ���� ��ų� �湮�� �̹� �� ���¶��
		//for ���� 8�� ���鼭 ���� ������ ����մϴ�.
	}
	//���� 8���� ��� �� ���� �Ҿ��ٸ�, 0�� ���ϵ˴ϴ�. ���� �ִ� �������� ��ã�⸦ �����Ѱ��Դϴ�.
	// 0�� ���ϵ�ٸ� ���� �Լ��� ȣ���ߴ� �Լ��� else�κ����� ���� ���� �־����ڸ��� UNMARK�մϴ�.
	//�׸��� ���� ������ ����մϴ�.
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
		//M�� * N�� 
		instream >> m >> n;
		instream >> start.y >> start.x;
		//��
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
