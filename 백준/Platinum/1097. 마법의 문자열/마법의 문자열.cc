#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N;
	vector<string> a(N);
	for (auto &i : a) cin >> i;
	cin >> K;
	vector<int> o(N);
	iota(o.begin(), o.end(), 0);

	int ans = 0;
	do {

		string P = "";
		for (int i = 0; i < N; i++) P += a[o[i]];
		vector<int> X(P.size());
		for (int i = 1; i < P.size(); i++) {
			X[i] = X[i - 1];
			while (X[i] > 0 && P[X[i]] != P[i]) X[i] = X[X[i] - 1];
			if (P[X[i]] == P[i]) X[i]++;
		}

		int cnt = 0;
		for (int i = 0, j = 0; i < P.size() * 2 - 1; i++) {
			while (j > 0 && P[j] != P[i%P.size()]) j = X[j - 1];
			if (P[j] == P[i%P.size()]) j++;
			if (j == P.size()) {
				cnt++;
				j = X[j - 1];
			}
		}
		ans += cnt == K;

	} while (next_permutation(o.begin(), o.end()));
	cout << ans;

}