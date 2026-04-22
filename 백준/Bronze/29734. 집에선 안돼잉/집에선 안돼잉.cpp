#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll N, M, T, S;
	cin >> N >> M >> T >> S;

	ll zip = S * ((N - 1) / 8) + N;
	ll dok = (2 * T + S) * ((M - 1) / 8) + T + M;
	
	cout << (zip < dok ? "Zip\n" : "Dok\n");
	cout << min(zip, dok);
}