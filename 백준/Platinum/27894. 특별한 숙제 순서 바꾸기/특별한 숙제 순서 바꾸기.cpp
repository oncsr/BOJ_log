#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int& i : A)	cin >> i;
	cin >> B[0] >> B[1];
	int prev = B[1] - B[0];
	bool ans = 0;
	for (int i = 2; i < N; i++) {
		cin >> B[i];
		int now = B[i] - B[i - 1];
		if (prev * now > 0)	ans = 1;
		prev = now;
	}
	ans |= (A == B);
	cout << (ans ? "POSSIBLE" : "IMPOSSIBLE");

}