#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, arr[101][101]{};
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int s = 0, e = 0, cnt = 0;
		for (int j = 1; j <= M; j++) {
			if (!arr[i][j])	continue;
			cnt++;
			arr[i][j] = 0;
			if (!s)	s = j;
			e = j;
		}
		if (!cnt)	continue;
		int floor = i + 1;
		while (floor <= N) {
			s = e;
			for (int j = s; j <= M; j++) {
				if (!arr[floor][j])	continue;
				cnt++;
				arr[floor][j] = 0;
				e = j;
			}
			floor++;
		}
		if (cnt)	ans++;
	}
	cout << ans;

}