#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;
	int ans = 0, t = 0;
	for (char i : s) {
		if (i == 'o' && !t)	t++;
		else if (i == 'i' && t == 1)	t++;
		else if (i == 'j' && t == 2)	t = 0, ans++;
	}
	if (!ans)	cout << "NIE";
	else	cout << ans;

}