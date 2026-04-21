#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, T, g = 0, day = 1, ans = 0;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		char a;
		cin >> a;
		int ch = a - '0';
		ll buy = 0, sell = 0, cycle = 0;
		if (g > 61)	cycle = -1;
		else	cycle = (g ? pow(2, g) : 1);
		

		// ch == 2일 경우, 아래 케이스처럼 맞춰주자.
		ll TT = T - day;
		if (ch == 2) {
			if (cycle == -1)	TT = -1;
			else {
				buy = min(TT, cycle);
				TT -= cycle;
			}
		}

		// ch == 1이고, T만큼의 시간이 남은거
		if (ch == 1)	buy = min(day, T);
		if (cycle == -1) {
			if (TT > 0)	ans += min(buy, TT);
		}
		else {
			if (TT >= cycle) {
				ans += buy;
				buy = 0;
				TT -= cycle;
			}
			else {
				if (TT > 0) {
					ans += min(buy, TT);
					buy = 0;
					TT -= cycle;
				}
			}
			//
			if (TT > 0) {
				ll repeat = TT / cycle / 2;
				ans += repeat * cycle;
				TT -= repeat * cycle * 2;
			}
			if (TT > 0) {
				ll two = TT % (cycle * 2);
				ans += max(0LL, two - cycle);
			}
		}

		if (ch == 1) {
			if (g < 62)	day += g ? pow(2, g) : 1;
			else	break;
		}
		g++;
	}
	cout << ans;
}