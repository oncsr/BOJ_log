#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, S = 0, inf = -1234567890;
	cin >> N >> M;
	vector<int> D(M + 1, inf);

	D[0] = 0;
	for (int s, p; N--;) {
		cin >> s >> p;
		vector<int> ND(M + 1, inf);
		for (int i = 0; i <= M; i++) {
			if (D[i] == inf)	continue;
			ND[i] = max(ND[i], D[i] - s);
			if (i + p <= M)	ND[i + p] = max(ND[i + p], D[i]);
			if (i + p + 1 <= M)	ND[i + p + 1] = max(ND[i + p + 1], D[i] + s);
		}
		D = ND;
	}
	int mx = *max_element(D.begin(), D.end());
	cout << (mx > 0 ? 'W' : (mx < 0 ? 'L' : 'D'));

}