#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	int cnt[101]{};
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char a;
			cin >> a;
			if (a == 'O')	cnt[j]++;
		}
	}
	for (int i = 1; i <= M; i++) {
		if (!cnt[i]) { cout << i; return 0; }
	}
	cout << "ESCAPE FAILED";

}