#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	vector<pair<string, int>> V;
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string a;
		int b;
		cin >> a >> b;
		V.push_back({ a,b });
	}
	set<string> S;
	for (int i = 0; i < k; i++) {
		string a;
		cin >> a;
		S.insert(a);
	}
	int s = 0;
	priority_queue<int, vector<int>, greater<>> Q1;
	priority_queue<int, vector<int>, less<>> Q2;

	for (auto i : V) {
		if (S.count(i.first))	s += i.second;
		else	Q1.push(i.second), Q2.push(i.second);
	}
	int l = 0, r = 0;
	for (int i = 0; i < m - k; i++) {
		l += Q1.top();
		r += Q2.top();
		Q1.pop();
		Q2.pop();
	}
	cout << s + l << ' ' << s + r;
}