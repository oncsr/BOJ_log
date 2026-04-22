#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, X, ans = 0;
	cin >> N >> M >> X;
	int repair[100000]{};
	int circle[100000]{};
	for (int i = 0; i < N; i++)	cin >> repair[i];
	for (int i = 0; i < M; i++)	cin >> circle[i];
	sort(repair, repair + N);
	sort(circle, circle + M);
	int s = 1, e = N, m = (s + e) / 2;
	int cnt = 0;
	while (s <= e) {
		cnt++;
		if (m > M) {
			if (s == e)	break;
			e = m;
		}
		else {
			long long ss = 0;
			for (int i = 0; i < m; i++)
				if (circle[M - m + i] < repair[i])
					ss += (long long)repair[i] - (long long)circle[M - m + i];
			if (ss > X) {
				if (s == e)	break;
				e = m;
			}
			else {
				ans = m;
				if (s == e)	break;
				s = m + 1;
			}
		}
		m = (s + e) / 2;
	}
	cout << ans;
}