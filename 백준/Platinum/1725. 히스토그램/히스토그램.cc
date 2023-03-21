#include <iostream>
#include <stack>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	stack<pair<ll, int> > S;	// { value, index }
	int N;
	cin >> N;
	ll a, mx = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (S.empty())	S.push({ a,i });
		else {
			mx = max(mx, a);
			ll g = 1;
			while (!S.empty() && S.top().first > a) {
				ll now = S.top().second;
				ll height = S.top().first;
				S.pop();
				if (S.empty()) {
					mx = max(mx, i * height);
				}
				else {
					while (!S.empty() && S.top().first == height) {
						S.pop();
					}
					if (S.empty()) {
						mx = max(mx, i * height);
					}
					else {
						mx = max(mx, (((ll)i - 1) - S.top().second) * height);
					}
				}
			}
			S.push({ a,i });
		}
	}
	while (!S.empty()) {
		ll now = S.top().second;
		ll height = S.top().first;
		S.pop();
		if (S.empty()) {
			mx = max(mx, N * height);
		}
		else {
			while (!S.empty() && S.top().first == height) {
				S.pop();
			}
			if (S.empty()) {
				mx = max(mx, N * height);
			}
			else {
				mx = max(mx, ((ll)N - ((ll)S.top().second + 1)) * height);
			}
		}
	}
	cout << mx;
}