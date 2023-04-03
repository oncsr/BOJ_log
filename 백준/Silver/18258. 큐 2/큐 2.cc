// 큐 배열로 구현

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int queue[2000000];
	int front = 0, back = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string op;
		cin >> op;
		if (op == "push") {
			int X;
			cin >> X;
			queue[back] = X;
			back++;
		}
		else if (op == "pop") {
			if (front == back) {
				cout << -1 << '\n';
			}
			else {
				cout << queue[front] << '\n';
				front++;
			}
		}
		else if (op == "size") {
			cout << back - front << '\n';
		}
		else if (op == "empty") {
			if (front == back) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (op == "front") {
			if (front == back) {
				cout << -1 << '\n';
			}
			else {
				cout << queue[front] << '\n';
			}
		}
		else if (op == "back") {
			if (front == back) {
				cout << -1 << '\n';
			}
			else {
				cout << queue[back - 1] << '\n';
			}
		}
	}

}