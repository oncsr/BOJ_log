#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, need = 1;
	stack<int> E;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (need == a) {
			need++;
			continue;
		}
		while (!E.empty() && need == E.top()) {
			E.pop();
			need++;
		}
		if (!E.empty() && E.top() < a) {
			cout << "Sad";
			return 0;
		}
		E.push(a);
	}
	cout << "Nice";

}