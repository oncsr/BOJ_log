#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> S(10);
int e[100]{};
int N, B;
string ans;
bool can(int n, int a, string w) {
	if (n == N - 2) {
		if (a == B) { ans = w; return 1; }
		return 0;
	}
	for (int i : S[a % 10]) {
		char g = '0' + (i % 10);
		if (can(n + 1, i, w + g))	return 1;
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 11; i <= 99; i++) {
		bool s = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) { s = 0; break; }
		}
		if (s)	S[i / 10].push_back(i);
		else	e[i]++;
	}

	int A;
	cin >> A >> B >> N;
	if (e[A] || e[B]) { cout << -1; return 0; }
	if (!((B / 10) & 1) || (B / 10) == 5) { cout << -1; return 0; }
	bool res = can(0, A, to_string(A));
	if (res)	cout << ans;
	else	cout << -1;
}