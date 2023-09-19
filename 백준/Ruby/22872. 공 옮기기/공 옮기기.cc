#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int n;
vector<ii> ans;

// 각 바구니의 공 개수
int cnt[4]{};

bool third_basket = 0;

void solve(int a, int b, int s, int e) {
	int o = 6 - s - e;
	int ch1 = (cnt[s] - (b - a + 1)) & 1;
	int ch2 = cnt[e] & 1;
	if (a == b) {
		ans.push_back({ s,e });
		cnt[s]--, cnt[e]++;
		return;
	}
	if (a == b - 1) {
		if (ch1 ^ ch2) {
			ans.push_back({ s,e });
			ans.push_back({ s,e });
		}
		else {
			ans.push_back({ s,o });
			ans.push_back({ s,e });
			ans.push_back({ o,e });
		}
		cnt[s] -= 2, cnt[e] += 2;
		return;
	}
	/*
	if (a == b - 2) {
		if (ch1 && ch2) {
			ans.push_back({ s,e });
			ans.push_back({ s,o });
			ans.push_back({ e,o });
			ans.push_back({ s,e });
			ans.push_back({ o,s });
			ans.push_back({ o,e });
			ans.push_back({ s,e });
		}
		else if (ch2) {
			ans.push_back({ s,o });
			ans.push_back({ s,e });
			ans.push_back({ s,e });
			ans.push_back({ o,e });
		}
		else if (ch1) {
			ans.push_back({ s,o });
			ans.push_back({ s,e });
			ans.push_back({ s,e });
			ans.push_back({ o,e });
		}
		else {
			ans.push_back({ s,o });
			ans.push_back({ s,o });
			ans.push_back({ s,e });
			ans.push_back({ o,e });
			ans.push_back({ o,e });
		}
		cnt[s] -= 3, cnt[e] += 3;
		return;
	}
	*/
	
	/*
	if (ch1 == 0 && ch2 == 0) {
		solve(a + 1, b - 1, s, e);
		ans.push_back({ s,o });
		ans.push_back({ s,o });
		cnt[s] -= 2, cnt[o] += 2;
		solve(a + 1, b - 1, e, s);
		ans.push_back({ o,e });
		ans.push_back({ o,e });
		cnt[o] -= 2, cnt[e] += 2;
		solve(a + 1, b - 1, s, e);
	}
	else {
		solve(a + 1, b - 1, s, o);
		ans.push_back({ s,e });
		ans.push_back({ s,e });
		cnt[s] -= 2, cnt[e] += 2;
		solve(a + 1, b - 1, o, e);
	}
	*/
	solve(a + 1, b - 1, s, o);
	ans.push_back({ s,e });
	ans.push_back({ s,e });
	cnt[s] -= 2, cnt[e] += 2;
	solve(a + 1, b - 1, o, e);
}

void print() {
	for (ii now : ans)
		cout << now.first << ' ' << now.second << '\n';
}

int main() {
	cin >> n;
	cnt[1] = n;
	if (n == 1) {
		cout << "1\n1 3";
		return 0;
	}
	if (n == 2) {
		cout << "3\n1 2\n1 3\n2 3";
		return 0;
	}
	solve(2, n, 1, 2);
	ans.push_back({ 1,3 });
	cnt[1]--, cnt[3]++;

	solve(2, n, 2, 3);

	cout << ans.size() << '\n';
	
	//print();

}