#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
int arr[6]{};
int ans = 0;

void sol(int day, int prev, int score) {
	if (day == N) {
		if (score >= M)	ans++;
		return;
	}
	for (int i = 0; i < 6; i++) {
		int place = i % 3;
		sol(day + 1, i % 3, score + arr[i] / (place == prev ? 2 : 1));
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < 6; i++)	cin >> arr[i];
	sol(0, -1, 0);
	cout << ans;

}