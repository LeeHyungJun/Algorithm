#include <stdio.h>

#define MAXSIZE 9
typedef enum { false, true } bool;
int queue[MAXSIZE];
int front;
int rear;

/*
���� ť�� �ٽ�.
1. fornt�� rear�� % �� ����Ѵ�.
2. ���� ���´� front = rear+1
3. �� �� ���´� front = rear
4. MAXSIZE-1��ŭ �ڷḦ ���� �� �ִ�.
*/

void init() {
	front = 0;
	rear = 0;
}

bool push(char pushValue) {
	//�������� �� �ƴ϶��
	if (front != ((rear + 1) % MAXSIZE)) {
		rear = (rear + 1) % MAXSIZE;
		queue[rear] = pushValue;
		return true;
	}
	else {
		printf("queue is full ! ");
		return false;
	}
}

char pop() {
	//�ֺ���°� �ƴ϶��
	/*�̹� push�� �ϸ鼭 rear�� %MAXSIZE�� �޾��� ������,
	rear % MAXSIZE �����൵�ȴ�. front�� ��������.*/
	if (front != rear) {
		front = (front + 1) % MAXSIZE;
		return queue[front];
	}
	else
		return -1;
}


void main() {
	int i = 0, count = 0;
	char popValue;
	char arr[MAXSIZE];
	fgets(arr, MAXSIZE, stdin);

	while (1) {
		if (arr[i++] == '\n')
			break;

		count++;
	}

	init();
	for (i = 0; i < count; i++) {
		if (push(arr[i])==0) {
			printf("push error :: num =  %d ", i);
		}
	}

	for (i = 0; i <= rear; i++) {
		printf("%c", queue[i]);
	}
	printf("\n");

	for (i = 0; i <= rear-1; i++) {
		printf("%c", pop());
	}
	
	//printf(" f : %d, r : %d", front, rear);
}