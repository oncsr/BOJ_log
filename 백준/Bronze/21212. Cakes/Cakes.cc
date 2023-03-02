#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
	int s = 10001;
	for (cin >> n; n--;) {
		cin >> a >> b;
		s = min(s, b / a);
	}
	cout << s;
}