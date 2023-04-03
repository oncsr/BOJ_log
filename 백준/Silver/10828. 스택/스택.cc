#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int arr[10000] = { 0 };
int id = 0;

void push(int ab) {
	arr[id] = ab;
	id++;
}

void pop() {
	if (id == 0)
		printf("-1\n");
	else {
		printf("%d\n", arr[id - 1]);
		arr[id - 1] = 0;
		id--;
	}
}

void size() {
	printf("%d\n", id);
}

void empty() {
	if (id == 0)
		printf("1\n");
	else
		printf("0\n");
}

void top() {
	if (id == 0)
		printf("-1\n");
	else
		printf("%d\n", arr[id - 1]);
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