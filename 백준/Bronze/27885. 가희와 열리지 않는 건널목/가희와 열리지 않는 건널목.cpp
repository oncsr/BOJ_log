#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[86400]{};
	int N, M, h, m, s;
	char t;
	cin >> N >> M;
	for (int a = 0; a < N + M; a++) {
		cin >> h >> t >> m >> t >> s;
		int T = h * 3600 + m * 60 + s;
		for (int i = T; i < T + 40; i++)	arr[i]++;
	}
	int ans = 0;
	for (int i = 0; i < 86400; i++)
		if (!arr[i])	ans++;
	cout << ans;
}