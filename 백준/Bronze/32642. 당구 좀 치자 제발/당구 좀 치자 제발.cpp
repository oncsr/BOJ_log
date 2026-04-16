#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	ll N, c = 0, s = 0, a;
	for (cin >> N; N--;) {
		int a;
		cin >> a;
		s += c += a ? 1 : -1;
	}
	cout << s;
 
}