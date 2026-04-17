#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string arr[500]{};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	for (int i = 0; i < n; i++) {
		int p, q;
		cout << "? " << arr[i] << endl;
		cin >> p;
		cout << "? " << arr[i] << endl;
		cin >> q;
		if (p || q) {
			cout << "! " << arr[i] << endl;
			return 0;
		}
	}
}