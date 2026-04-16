#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, A, B;
	cin >> N >> A >> B;
	int T[100]{};
	for (int i = 0; i < N; i++)	cin >> T[i];
	sort(T, T + N);

	int ans = 0;
	for (int x = 0; x < A; x++) {
		int suc = 0, tm = 0;
		for (int i = 0; i < N; i++) {
			int cnt = suc, t = tm + B * x, d = A - x;
			for (int j = i; j < N; j++) {
				if (T[j] >= t + d) {
					t += d;
					cnt++;
				}
			}
			ans = max(ans, cnt);
			if (T[i] >= tm + A) {
				tm += A;
				suc++;
			}
		}
	}
	cout << ans;

}