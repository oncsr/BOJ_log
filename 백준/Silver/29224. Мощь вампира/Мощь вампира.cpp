#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	int s = 1e9, g = 0;
	int ans[100]{};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++)	cout << "+ ";
		for (int j = n - i; j < n; j++)	cout << "- ";
		cout << endl;
		if (s == 1e9) { cin >> s; continue; }
		int p;
		cin >> p;
		ans[n - i] = (s - p) / 2;
		g += (s - p) / 2;
		s = p;
	}
	cout << "answer: " << s + g << ' ';
	for (int i = 1; i < n; i++)	cout << ans[i] << ' ';
	cout << endl;

}