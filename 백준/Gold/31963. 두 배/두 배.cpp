#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, ans = 0;	// ans : 정답을 저장하는 변수
	// prev : 직전의 원소를 저장하는 변수
	// prev_cnt : 직전 원소에 적용된 연산의 횟수
	ll prev = 0, prev_cnt = 0;
	cin >> N >> prev;
	for (int i = 1; i < N; i++) {
		ll c;
		cin >> c;
		ll a = prev, b = c, cnt = 0;
		if (a == b) {
			ans += prev_cnt;
			continue;
		}
		// i번째 원소에 적용해야 하는 쿼리의 최소 횟수를 직접 구한다.
		if (a > b) {
			while (a > b) {
				b <<= 1;
				cnt++;
			}
		}
		else {
			while (a < b) {
				a <<= 1;
				cnt--;
			}
			if (a != b)	cnt++;
		}
		cnt = max(0LL, prev_cnt + cnt);
		ans += cnt;
		prev_cnt = cnt;
		prev = c;
	}
	cout << ans;

}