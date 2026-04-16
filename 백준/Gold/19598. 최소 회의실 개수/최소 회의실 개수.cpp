#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return abs(a) < abs(b);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	// S : 회의 시작 시간들
	// E : 회의 종료 시간들
	vector<int> E;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		E.push_back(a);
		E.push_back(-b);
	}
	sort(E.begin(), E.end(), cmp);

	int ans = 0, cnt = 0, idx = 0;
	// 시간 순으로 보기
	while (idx < E.size()) {
		int now = abs(E[idx]);
		// 현재 시간에 발생하는 이벤트를 모두 처리
		while (idx < E.size() && abs(E[idx]) == now) {
			// 이벤트가 회의 시작이라면, 방의 개수 늘리기
			if (E[idx] >= 0)	cnt++;
			// 이벤트가 회의 종료라면, 방의 개수 줄이기
			else	cnt--;
			idx++;
		}
		ans = max(ans, cnt);
	}

	cout << ans;

}