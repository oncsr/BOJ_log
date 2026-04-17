#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	for (cin >> N; N; cin >> N) {
		vector<vector<int>> V(101);
		vector<int> arr(N);
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			arr[i] = a;
			for (int j = 1; j * j <= a; j++) {
				if (a % j)	continue;
				V[j].push_back(i);
				if (a / j != j)	V[a / j].push_back(i);
			}
		}
		vector<vector<int>> R(101);
		for (int i = 1; i <= 100; i++) {
			if (V[i].empty())	continue;
			int prev = V[i][0] - 1;
			for (int j : V[i]) {
				if (j != prev + 1)	R[i].push_back(prev + 1);
				prev = j;
			}
			R[i].push_back(prev + 1);
			if (prev + 1 != N)	R[i].push_back(N);
		}
		set<int> S;
		for (int i = 0; i < N; i++) {
			int g = i, c = arr[i];
			S.insert(c);
			while (c != 1) {
				g = R[c][upper_bound(R[c].begin(), R[c].end(), g) - R[c].begin()];
				if (g >= N)	break;
				c = gcd(c, arr[g]);
				S.insert(c);
			}
		}
		cout << S.size() << '\n';
	}
}