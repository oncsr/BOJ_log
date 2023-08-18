#include <iostream>
#include <stack>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N, a;
	ll s = 0;
	stack<ll> S;
	for (cin >> N; N--;) {
		cin >> a;
		if (!S.empty()) {
			if (a > S.top()) {
				while (!S.empty() && a > S.top()) {
					ll temp = S.top(), g = 1;
					S.pop();
					if (!S.empty()) {
						if (temp < S.top())	s += 2;
						else {
							while (!S.empty() && temp == S.top()) {
								S.pop();
								g++;
							}
							s += g * (g + 1) / 2;
							if (!S.empty())	s += g;
						}
					}
					else	s++;
				}
			}
		}
		S.push(a);
	}
	while (!S.empty()) {
		ll a = S.top();
		S.pop();
		if (!S.empty()) {
			if (a < S.top())	s++;
			else {
				ll g = 0;
				while (!S.empty() && S.top() == a) {
					S.pop();
					g++;
				}
				s += g * (g + 1) / 2;
				if (!S.empty())	s += (g + 1);
			}
		}
	}
	cout << s;
}