#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

void sol() {

	int TC = 1;
	//cin >> TC;
	for (; TC--;) {

		int N, M;
		cin >> N;
		int vis[1001]{}, p = 0;
		while (p != N) {
			p = 0;
			cin >> M;
			vector<int> V(M);
			int mn = 1001;
			for (int& i : V) {
				cin >> i;
				if (vis[i] <= mn)	p = i, mn = vis[i];
			}
			vis[p]++;
			cout << p << endl;
		}

	}

}

int main() {

	sol();

}