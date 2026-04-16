#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 3; j <= s.size() - i; j++) {
			int acnt = 0, ncnt = 0;
			for (int k = i; k < i + j; k++) {
				acnt += s[k] == 'A';
				ncnt += s[k] == 'N';
			}
			if (acnt == 2 && s[i] == 'A' && s[i + j - 1] == 'A' && ncnt == 1)	ans++;
		}
	}
	cout << ans;

}