#include <stdio.h>
#define MAXSIZE 100

typedef enum { false, true } bool;

int stack[MAXSIZE];
int top;

bool init_stack() {
	top = -1;
}

bool isFull() {
	if (top + 1 >= MAXSIZE)
		return true;
	else
		return false;
}

bool isEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}

bool push(char pushValue) {
	if (top + 1 < MAXSIZE) {
		stack[++top] = pushValue;
		return true;
	}
	else 
		return false;
}

char pop() {
	if (top!=-1)
		return stack[top--];
	else {
		return -1;
	}
}


void main() {
	int i=0,count=0;
	char popValue;
	char arr[MAXSIZE];
	fgets(arr, MAXSIZE, stdin);

	while (1) {
		count++;
		if (arr[i++] == '\n')
			break;
	}

	init_stack();

	for (i = 0; i < count-1; i++) {
		if (!push(arr[i])) {
			printf("push error :: num =  %d ", i);
		}
	}

	for (i = 0; i < count-1; i++) {
		printf("%c", pop());
	}
}