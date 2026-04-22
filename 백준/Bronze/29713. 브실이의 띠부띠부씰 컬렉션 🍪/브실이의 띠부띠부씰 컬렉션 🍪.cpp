#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, s = 0, cnt[26]{};
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		cnt[a - 'A']++;
	}
	string ch = "BRONZESILV";
	int mn = 1000;
	for (char i : ch) {
		if (i == 'R' || i == 'E')	mn = min(mn, cnt[i - 'A'] / 2);
		else	mn = min(mn, cnt[i - 'A']);
	}
	cout << mn;
}