#include <stdio.h>
#include <string.h>

void swap(char* a, char* b) {
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permutation(char *str, int first, int last) {
	int i;
	int range = last - first;
	if (range == 1) {
		printf("%s\n", str);
		return;
	}
	
		for (i = 0; i < range; i++) {
			swap(&str[first], &str[first + i]);
			permutation(str, first + 1, last);
			swap(&str[first], &str[first + i]);
		}
	
}

int main() {
	char str[] = "abc";
	permutation(str,0,strlen(str));
	return 0;
}