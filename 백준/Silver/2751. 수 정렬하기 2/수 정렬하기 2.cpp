#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	set<int> S;
	for (cin >> n; n--;) {
		int a;
		cin >> a;
		S.insert(a);
	}
	for (int i : S)	cout << i << '\n';
	

}