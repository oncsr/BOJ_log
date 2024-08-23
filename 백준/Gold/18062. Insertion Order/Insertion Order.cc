#include <bits/stdc++.h>
using namespace std;

void sol(int s, int e, int d) {
	int cnt = e - s + 1, root;
	if (cnt <= 2 * d - 1) {
		root = s + d - 1;
		for (int i = root; i >= s; i--)	cout << i << ' ';
		for (int i = root + 1; i <= e; i++)	cout << i << ' ';
		return;
	}
	root = (s + e) >> 1;
	cout << root << ' ';
	sol(s, root - 1, d - 1);
	sol(root + 1, e, d - 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	if (k < 31 && n >= (1 << k))	return cout << "impossible", 0;

	sol(1, n, k);

}