#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int dep[100001]{}, odd = 0, even = 1, N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		int a;
		cin >> a;
		dep[i] = dep[a] ^ 1;
		odd += dep[i] & 1;
		even += dep[i] & 1 ^ 1;
	}

	cout << min(odd, even) + abs(odd - even);

}