#include <stdio.h>

#define MAXSIZE 9
typedef enum { false, true } bool;
int queue[MAXSIZE];
int front;
int rear;

/*
원형 큐의 핵심.
1. fornt와 rear를 % 를 사용한다.
2. 꽉찬 상태는 front = rear+1
3. 텅 빈 상태는 front = rear
4. MAXSIZE-1만큼 자료를 넣을 수 있다.
*/

void init() {
	front = 0;
	rear = 0;
}

bool push(char pushValue) {
	//꽉찬상태 가 아니라면
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
	//텅빈상태가 아니라면
	/*이미 push를 하면서 rear가 %MAXSIZE를 겪었기 떄문에,
	rear % MAXSIZE 안해줘도된다. front도 마찬가지.*/
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