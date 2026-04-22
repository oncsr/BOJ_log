#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll N, P, H;
	cin >> N >> P >> H;

	// height[i] = i번 접었을 때 P가 있어야 하는 높이
	ll height[61] = { 1 };
	height[N] = H;
	for (ll i = N - 1; i >= 1; i--) {
		if (height[i + 1] > (1LL << i))	height[i] = (1LL << (i + 1)) - height[i + 1] + 1;
		else	height[i] = height[i + 1];
	}

	bool right = false;	// 지금 오른쪽 구역에 있는가?
	ll x = P, G = (1LL << N);
	if (P > G / 2)	right = true;
	string ans = "";
	for (ll i = 1; i <= N; i++) {
		if (height[i-1] != height[i]) {
			// 높이가 바뀌어야 하는 경우
			if (right)	ans += 'R';
			else	ans += 'L';
			x = G + 1 - x;
			if (x > G / 2)	x -= G / 2;
		}
		else {
			// 높이가 그대로여야 하는 경우
			if (right) {
				ans += 'L';
				x -= G / 2;
			}
			else	ans += 'R';
		}
		G >>= 1;
		if (x > G / 2)	right = true;
		else	right = false;
	}
	cout << ans;
}