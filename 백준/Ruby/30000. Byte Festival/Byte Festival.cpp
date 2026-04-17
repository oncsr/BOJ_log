#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	if (N == 0)	cout << "BOJ 30000\n";
	else if (N == 1) {
		for (ll g = 989345275647LL; g != 1;) {
			cout << g << '\n';
			if (g & 1)	g = (g * 3 + 1);
			else g /= 2;
		}
		cout << 1 << '\n';
	}
	else if (N == 2) {

	}

}