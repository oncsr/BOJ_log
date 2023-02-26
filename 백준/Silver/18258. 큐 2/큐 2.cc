#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

typedef struct Node {
	int data;
	struct Node* next;
}Node;
typedef struct Queue {
	Node* front;
	Node* rear;
	int size;
}Queue;

void queue_setting(Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

int empty(Queue* queue) {
	return (queue->size == 0 ? 1 : 0);
}

void push(Queue* queue, int x) {
	Node* temp = (Node *)malloc(sizeof(*temp));
	temp->data = x;
	temp->next = NULL;
	if (empty(queue))
		queue->front = temp;
	else
		queue->rear->next = temp;
	queue->rear = temp;
	queue->size++;
}

int pop(Queue* queue) {
	if (empty(queue))
		return -1;
	else {
		Node* temp = queue->front;
		queue->front = temp->next;
		if (queue->front == NULL)
			queue->rear = NULL;
		int value = temp->data;
		free(temp);
		queue->size--;
		return value;
	}
}

int size(Queue* queue) {
	return queue->size;
}

int front(Queue* queue) {
	if (empty(queue))
		return -1;
	else
		return queue->front->data;
}

int back(Queue* queue) {
	if (empty(queue))
		return -1;
	else
		return queue->rear->data;
}

int main() {
	Queue q;
	queue_setting(&q);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		string op;
		cin >> op;
		if (op == "push") {
			int x;
			cin >> x;
			push(&q, x);
		}
		else if (op == "pop")
			cout << pop(&q) << '\n';
		else if (op == "size")
			cout << size(&q) << '\n';
		else if (op == "empty")
			cout << empty(&q) << '\n';
		else if (op == "front")
			cout << front(&q) << '\n';
		else if (op == "back")
			cout << back(&q) << '\n';
	}
}