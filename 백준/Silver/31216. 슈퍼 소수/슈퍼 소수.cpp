#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int e[1000001]{};
	for (int i = 2; i * i <= 1000000; i++) {
		if (!e[i]) {
			for (int j = i * i; j <= 1000000; j += i)
				e[j] = 1;
		}
	}
	vector<int> prime;
	for (int i = 2; i <= 1000000; i++) {
		if (!e[i])	prime.push_back(i);
	}
	vector<int> sup;
	int cnt = 0;
	for (int i = 1; cnt < 3000; i++) {
		if (!e[i + 1]) {
			sup.push_back(prime[i]);
			cnt++;
		}
	}

	int T;
	for (cin >> T; T--;) {
		int n;
		cin >> n;
		cout << sup[n - 1] << '\n';
	}

}