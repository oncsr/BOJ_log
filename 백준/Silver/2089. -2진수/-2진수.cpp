#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	stack<int> S;
	int N;
	cin >> N;
	if (N == 0) { cout << 0; return 0; }
	while (N) {
		int t = abs(N) & 1;
		S.push(t);
		N = -(N - t) / 2;
	}
	while (!S.empty())	cout << S.top(), S.pop();

}