#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<pair<pair<ll, ll>, bool>, pair<priority_queue<ll, vector<ll>, greater<> >, ll> > balloon;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		bool dir = true;
		if (a < 0)	dir = false;
		if (a != 0 && b != 0) {
			ll g = gcd(abs(a), abs(b));
			a /= g, b /= g;
		}
		else {
			if (a == 0)	b = (b > 0 ? 1 : -1);
			else	a = (a > 0 ? 1 : -1);
		}
		if (balloon[{ {a, b}, dir}].first.size() == 0)
			balloon[{ {a, b}, dir}].second = 0;
		balloon[{ {a, b}, dir}].first.push(c);
	}
	for (int i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		bool dir = true;
		if (a < 0)	dir = false;
		if (a != 0 && b != 0) {
			ll g = gcd(abs(a), abs(b));
			a /= g, b /= g;
		}
		else {
			if (a == 0)	b = (b > 0 ? 1 : -1);
			else	a = (a > 0 ? 1 : -1);
		}
		if (balloon[{ {a, b}, dir}].first.size() == 0) {
			cout << N << '\n';
			continue;
		}
		balloon[{ {a, b}, dir}].second += c;
		while (!balloon[{ {a, b}, dir}].first.empty()) {
			if (balloon[{ {a, b}, dir}].first.top() <= balloon[{ {a, b}, dir}].second) {
				balloon[{ {a, b}, dir}].first.pop();
				N--;
			}
			else	break;
		}
		cout << N << '\n';
	}
}