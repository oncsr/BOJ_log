#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, turnReverse;
vector<int> G;
vector<int> D;

int dp(int n) {
	if (D[n] != -1) return D[n];
	int can = 0;
	for (int g : G) if ((n&g) == 0) {
		can++;
		if (dp(n | g) == 0) return D[n] = 1;
	}
	return D[n] = can ? 0 : turnReverse;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		
		turnReverse = 0;
		cin >> N >> M;
		int C[151]{};
		vector<int> L;
		for (int i = 0, a; i < M; i++) {
			cin >> a;
			int origin = a;
			if (a == 1) {
				turnReverse ^= 1;
				continue;
			}
			for (int j = 2; j*j <= a; j++) {
				if (a%j) continue;
				while (a%j == 0) a /= j;
				L.push_back(j);
			}
			if (a > 75) {
				turnReverse ^= 1;
				continue;
			}
			if (a != 1) L.push_back(a);
			C[origin]++;
		}

		sort(L.begin(), L.end());
		L.erase(unique(L.begin(), L.end()), L.end());
		K = L.size();

		G = vector<int>();
		for (int i = 1; i <= N; i++) {
			int res = 0;
			if (!C[i]) continue;
			for (int j = 0; j < K; j++) if ((i%L[j]) == 0) res |= (1 << j);
			G.push_back(res);
		}

		D = vector<int>(1 << K, -1);
		cout << (dp(0) ? "amsminn\n" : "bnb2011\n");
	}

}