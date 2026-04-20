#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;

	int cnt[2]{};
	char temp = s[0];
	for (char i : s) {
		if (temp != i)	cnt[temp - '0']++;
		temp = i;
	}
	cnt[temp - '0']++;

	cout << min(cnt[0], cnt[1]);

}