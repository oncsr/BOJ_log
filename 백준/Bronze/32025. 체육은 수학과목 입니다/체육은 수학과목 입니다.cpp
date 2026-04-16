#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int h, w;
	cin >> h >> w;
	h *= 100, w *= 100;
	cout << min(h, w) / 2;

}