#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int e[100001] = { 1,1 };
	for (int i = 2; i * i <= 100000; i++)
		if (!e[i])
			for (int j = i * i; j <= 100000; j += i)
				e[j] = 1;


	int idx[100001]{}, id = 1;
	vector<int> prime = { 0 };
	for (int i = 2; i <= 100000; i++) {
		if (!e[i]) {
			idx[i] = id++;
			prime.push_back(i);
		}
	}

	int upper[100001]{}, lower[100001]{}, temp = 0;
	vector<int> st1, st2;
	for (int i = 1; i <= 100000; i++) {
		st1.push_back(i);
		if (!e[i]) {
			for (int j : st1)	upper[j] = i;
			for (int j : st2)	lower[j] = temp;
			temp = i;
			st1 = vector<int>();
			st2 = vector<int>();
		}
		st2.push_back(i);
	}
	vector<ll> F1(prime.size() + 1), F2(prime.size() + 1);
	for (int i = 1; i < prime.size(); i++) {
		F1[i] = F1[i - 1] + (ll)((i & 1) ? 3 * prime[i] : -1 * prime[i]);
		if (i == 1)	continue;
		F2[i] = F2[i - 1] + (ll)((i & 1) ? -1 * prime[i] : 3 * prime[i]);
	}
	int T;
	for (cin >> T; T--;) {
		int a, b;
		cin >> a >> b;
		int p = idx[upper[a]], q = idx[lower[b]];
		if (p & 1)	cout << F1[q] - F1[p - 1] << '\n';
		else	cout << F2[q] - F2[p - 1] << '\n';
	}
}