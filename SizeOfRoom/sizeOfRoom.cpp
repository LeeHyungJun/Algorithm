/**************************
컴퓨터공학부 20113315 이형준
*****************************/
#include<iostream>
#include<fstream>
#include <cstring>
#include <algorithm>

#define SIZE 9
using namespace std;
int row, col;
int RoomSizeCnt = 0;
//index means that number of room. value means that Size of room
int RoomsizeArr[10000] = { 0 };

//To use qsort,This function goes into 4th parameter to ascending order
int compare(const void * a, const void * b)
{
	return -(*(int*)a - *(int*)b);
}
//this func is recursive func.
void sizeOfRoom(char arr[100][100], int x, int y, char oldColor, char newColor) {

	// base step.
	if (arr[x][y] != oldColor) {
		return;
	}

	//recursive step.
	else
	{
		arr[x][y] = '1';
		//RoomSizeCnt means that size Of Room
		RoomSizeCnt++;
		sizeOfRoom(arr, x - 1, y, oldColor, newColor);
		sizeOfRoom(arr, x + 1, y, oldColor, newColor);
		sizeOfRoom(arr, x, y - 1, oldColor, newColor);
		sizeOfRoom(arr, x, y + 1, oldColor, newColor);
	}
}

int main(void)
{
	int testCase, num = 0;
	char str[1001];
	fstream instream("input.txt", ios::in);
	instream >> testCase;
	//testCase 
	for (int q = 0; q < testCase; q++)
	{
		int a = 0;
		col = 0; row = 0;
		instream >> col >> row;		//29 13
		char arr[100][100];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				instream >> arr[i][j];
			}
		}
		////////////////insert size of room to Arr.//////////////
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				RoomSizeCnt = 0;
				sizeOfRoom(arr, i, j, '.', '+');
				if (RoomSizeCnt != 0) {
					RoomsizeArr[a++] = RoomSizeCnt;
				}
			}
		}
		// array  about size of room is sorted. 
		qsort(RoomsizeArr, a, sizeof(int), compare);
		// a means that room number.
		cout << a << endl;
		for (int i = 0; i < a; i++)
			cout << RoomsizeArr[i] << " ";

		cout << endl;
		// initialize.
		RoomsizeArr[10000] = { 0 };
		a = 0;

	}
	return 0;
}
