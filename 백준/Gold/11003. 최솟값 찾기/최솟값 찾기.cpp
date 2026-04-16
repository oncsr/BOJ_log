#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, L;
	cin >> N >> L;
	deque<pair<int, int>> D;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		while (!D.empty() && D.back().first >= a)	D.pop_back();
		D.emplace_back(a, i);
		while (i - D.front().second >= L)	D.pop_front();
		cout << D.front().first << ' ';
	}

}