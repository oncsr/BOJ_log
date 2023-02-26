#include <stdio.h>
#include <string.h>

int arr[10000] = { 0 };
int index = 0;

void push(int ab) {
	arr[index] = ab;
	index++;
}

void pop() {
	if (index == 0)
		printf("-1\n");
	else {
		printf("%d\n", arr[index - 1]);
		arr[index - 1] = 0;
		index--;
	}
}

void size() {
	printf("%d\n", index);
}

void empty() {
	if (index == 0)
		printf("1\n");
	else
		printf("0\n");
}

void top() {
	if (index == 0)
		printf("-1\n");
	else
		printf("%d\n", arr[index - 1]);
}

int main() {
	int num;
	scanf("%d", &num);
	
	for (; num > 0; num--) {
		char word[10];
		scanf("%s", word);
		if (strcmp(word, "push") == 0) {
			int x;
			scanf("%d", &x);
			push(x);
		}
		else if (strcmp(word, "pop") == 0) {
			pop();
		}
		else if (strcmp(word, "size") == 0) {
			size();
		}
		else if (strcmp(word, "empty") == 0)	empty();
		else	top();
	}
}