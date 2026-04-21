#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, K;
	cin >> N >> K;
	cout << ((K - 1) * 2019201913 + N * 2019201949) % 2019201997;
}