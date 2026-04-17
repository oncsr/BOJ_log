#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll N, K;
	cin >> N >> K;
	ll g = gcd(N, K);
	N /= g, K /= g;
	if (K > N - K)	K = N - K;

	cout << N * (K - 1);

}