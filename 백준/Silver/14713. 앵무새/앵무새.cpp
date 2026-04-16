#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	cin.ignore();
	queue<string> Q[101]{};
	for (int i = 0; i < N + 1; i++) {
		string line;
		getline(cin, line);
		string temp = "";
		for (char j : line) {
			if (j == ' ') {
				Q[i].push(temp);
				temp = "";
			}
			else	temp += j;
		}
		Q[i].push(temp);
	}

	while (!Q[N].empty()) {
		string now = Q[N].front();
		Q[N].pop();
		bool find = 0;
		for (int i = 0; i < N; i++) {
			if (!Q[i].empty() && Q[i].front() == now) {
				Q[i].pop();
				find = 1;
				break;
			}
		}
		if (!find) {
			cout << "Impossible";
			return 0;
		}
	}
	for (int i = 0; i < N; i++) {
		if (!Q[i].empty()) {
			cout << "Impossible";
			return 0;
		}
	}
	cout << "Possible";

}