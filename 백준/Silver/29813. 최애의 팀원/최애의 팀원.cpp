#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	deque<pair<string, int>> D;
	for (int i = 1; i <= N; i++) {
		string a;
		int b;
		cin >> a >> b;
		D.push_back({ a,b });
	}

	while (D.size() > 1) {
		int cnt = D.front().second - 1;
		D.pop_front();
		cnt %= int(D.size());
		for (int j = 0; j < cnt; j++) {
			D.push_back(D.front());
			D.pop_front();
		}
		D.pop_front();
	}
	cout << D.front().first;

}