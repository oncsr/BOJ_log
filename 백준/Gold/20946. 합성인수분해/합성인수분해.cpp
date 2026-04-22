#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;
	vector<ll> arr;
	vector<ll> sosu;
	int e[1000001]{};
	for (ll i = 2; i * i <= 1000000; i++) {
		if (!e[i]) {
			for (ll j = i * 2; j <= 1000000; j += i)
				e[j] = 1;
		}
	}
	for (ll i = 2; i <= 1000000; i++)
		if (!e[i])	sosu.push_back(i);
	for (ll g : sosu) {
		while (N % g == 0) {
			N /= g;
			arr.push_back(g);
		}
	}
	if (N > 1)	arr.push_back(N);
	if (arr.size() <= 1) {
		cout << -1;
		return 0;
	}
	for (ll i = 0; i < arr.size(); i += 2) {
		if (arr.size() - i > 3)	cout << arr[i] * arr[i + 1] << ' ';
		else {
			ll g = 1;
			while (i < arr.size())	g *= arr[i++];
			cout << g;
		}
	}
}