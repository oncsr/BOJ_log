#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// 나보다 작은 애
	priority_queue<ll, vector<ll>, less<> > Q1;
	// 나보다 큰 애
	priority_queue<ll, vector<ll>, greater<> > Q2;
	int n;
	cin >> n;
	ll a, mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mx = max(mx, a);
		if (a < 2)	Q1.push(a);
		else	Q2.push(a);
	}
	int s = 0;
	ll cur = 2;
	while (!Q1.empty() && !Q2.empty()) {
		if (cur == mx)	break;
		cur += Q1.top();
		Q1.pop();
		s++;
		while (!Q2.empty() && Q2.top() < cur) {
			Q1.push(Q2.top());
			Q2.pop();
		}
	}
	if (Q2.empty() || cur == mx)	cout << s;
	else	cout << "NIE";
}