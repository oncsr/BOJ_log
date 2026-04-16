#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	int ans = 0;
	while (N > 0) {
		string n = to_string(N);

		// next : N에서 1을 모두 제외한 문자열
		string next = "";
		// cnt : N에 존재하는 1의 개수
		int cnt = 0;
		for (char i : n) {
			if (i != '1')	next += i;
			else	cnt++;
		}

		// 만약 N에 1이 없다면, N을 1 감소시킨다.
		if (n == next) {
			N--;
			ans++;
		}
		// N에 1이 있다면, 1을 모두 제외한 숫자로 바꿔준다.
		else {
			if (next.empty())	N = 0;
			else	N = stoi(next);
			ans += cnt;
		}
	}
	cout << ans;

}