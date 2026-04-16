#include <bits/stdc++.h>
using namespace std;
using appo = tuple<string, int, int>;
 
struct cmp {
	bool operator()(appo b, appo a) {
		return get<1>(a) < get<1>(b);
	}
};
 
int main() {
	int N;
	cin >> N;
	if (N == 0) { cout << 0; return 0; }
	priority_queue<appo, vector<appo>, cmp> Q;
	for (int i = 0; i < N; i++) {
		string a;
		int b, c, d;
		cin >> a >> b >> c >> d;
		Q.emplace(a, b * 7 + c, d);
	}
 
	map<string, int> money;
	for (int i = 0; i < N; i++) {
		string a;
		int b;
		cin >> a >> b;
		money[a] = b;
	}
 
	set<int> S;
	while (!Q.empty()) {
		auto [name, date, price] = Q.top();
		Q.pop();
		if (price <= money[name]) {
			money[name] -= price;
			S.insert(date);
		}
	}
	int prev = *S.begin() - 1, ans = 0, cnt = 0;
	for (int i : S) {
		if (i == prev + 1)	cnt++;
		else	cnt = 1;
		prev = i;
		ans = max(ans, cnt);
	}
	cout << ans;
 
}