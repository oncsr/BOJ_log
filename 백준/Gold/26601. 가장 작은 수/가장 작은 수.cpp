#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	int e[2000001]{};
	for (int i = 2; i * i <= 2000000; i++)
		if (!e[i])
			for (int j = i * i; j <= 2000000; j += i)
				e[j] = 1;
	priority_queue<ll, vector<ll>, greater<> > Q;
	for (ll i = 2; i <= 2000000; i++)
		if (!e[i])
			Q.push(i);

	ll ans = 1, mod = 2000003;
	while (N--) {
		ll G = Q.top();
		ans = (ans * G) % mod;
		Q.pop();
		Q.push(G * G);
	}
	cout << ans;
}