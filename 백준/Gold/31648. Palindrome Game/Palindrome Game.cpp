#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	for (cin >> T; T--;) {
		string a;
		cin >> a;
		cout << (a.back() == '0' ? "E\n" : "B\n");
	}

}