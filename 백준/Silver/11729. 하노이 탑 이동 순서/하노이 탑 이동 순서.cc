#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

// 현재 위치가 now이고 크기가 n인 하노이 탑을 dest에 놓는 함수
vector<ii> ans;

void Hanoi(int n, int now, int dest) {
	if (n == 1) {
		ans.push_back({ now, dest });
		return;
	}
	if (now == 1) {
		if (dest == 2)	Hanoi(n - 1, now, 3);
		else	Hanoi(n - 1, now, 2);
		ans.push_back({ now, dest });
		if (dest == 2)	Hanoi(n - 1, 3, 2);
		else	Hanoi(n - 1, 2, 3);
	}
	else if (now == 2) {
		if (dest == 1)	Hanoi(n - 1, now, 3);
		else	Hanoi(n - 1, now, 1);
		ans.push_back({ now, dest });
		if (dest == 1)	Hanoi(n - 1, 3, 1);
		else	Hanoi(n - 1, 1, 3);
	}
	else {
		if (dest == 1)	Hanoi(n - 1, now, 2);
		else	Hanoi(n - 1, now, 1);
		ans.push_back({ now, dest });
		if (dest == 1)	Hanoi(n - 1, 2, 1);
		else	Hanoi(n - 1, 1, 2);
	}
}

int main() {
	int N;
	cin >> N;
	Hanoi(N, 1, 3);
	cout << ans.size() << '\n';
	for (ii cur : ans)
		cout << cur.first << ' ' << cur.second << '\n';
}