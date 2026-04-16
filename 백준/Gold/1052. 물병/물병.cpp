#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, ans = 0;
	cin >> n >> k;
    while(__builtin_popcount(n) > k) ans++, n++;
	cout << ans;
}