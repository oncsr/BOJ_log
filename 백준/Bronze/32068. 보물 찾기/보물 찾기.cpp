#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	for (cin >> T; T--;) {
		int L, S, R;
		cin >> L >> R >> S;
		L -= S, R -= S;
		S = 0;
		cout << min(abs(L) * 2 + 1, R * 2) << '\n';
	}

}