#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	string a, b, c;
	cin >> a >> b >> c;
	map<char, int> M;
	for (int h = 1; h < 4; h++) {
		M['H'] = h;
		for (int j = 1; j < 4; j++) {
			if (h == j)	continue;
			M['J'] = j;
			for (int s = 1; s < 4; s++) {
				if (j == s || h == s)	continue;
				M['S'] = s;
				string A = "", B = "", C = "";
				for (int i = 0; i < N; i++) {
					A += M[a[i]];
					B += M[b[i]];
					C += M[c[i]];
				}
				if (A > B && B > C) { cout << "HJS! HJS! HJS!"; return 0; }
			}
		}
	}
	cout << "Hmm...";
}