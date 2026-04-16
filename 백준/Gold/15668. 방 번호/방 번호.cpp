#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	for (int a = 1; a < N; a++) {
		int b = N - a;
		string A = to_string(a), B = to_string(b);
		if (A.size() + B.size() > 10)	break;
		int cnt[10]{}, x = 0;
		for (int j : A)	x = max(x, ++cnt[j - '0']);
		for (int j : B)	x = max(x, ++cnt[j - '0']);
		if (x == 1)	return cout << A << " + " << B, 0;
	}
	cout << -1;
	
}