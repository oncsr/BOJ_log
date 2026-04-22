#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int stack[10000];
	int id = 0;
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string op;
		cin >> op;
		if (op == "push") {
			int X;
			cin >> X;
			stack[id] = X;
			id++;
		}
		else if (op == "pop") {
			if (id == 0) {
				cout << -1 << '\n';
			}
			else {
				id--;
				cout << stack[id] << '\n';
			}
		}
		else if (op == "size") {
			cout << id << '\n';
		}
		else if (op == "empty") {
			if (id == 0) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (op == "top") {
			if (id == 0) {
				cout << -1 << '\n';
			}
			else {
				cout << stack[id - 1] << '\n';
			}
		}
	}

}