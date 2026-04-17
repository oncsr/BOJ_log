#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, G[1001] = { 0,0,1,1,2 };
	cin >> N;
	for (int i = 5; i <= N; i++) {
		set<int> S;
		for (int j = i - 2; j >= (i - 2) / 2; j--)	S.insert(G[j] ^ G[i - j - 2]);
		int c = 0;
		for (int i : S) {
			if (i != c)	break;
			c++;
		}
		G[i] = c;
	}
	cout << (G[N] ? 1 : 2);
}
