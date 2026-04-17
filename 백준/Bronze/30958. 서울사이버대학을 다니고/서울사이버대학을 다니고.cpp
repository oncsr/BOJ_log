#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	cin.ignore();
	string s;
	getline(cin, s);
	int cnt[26]{}, mx = 0;
	for (char a : s) {
		if (a == ' ' || a == ',' || a == '.')	continue;
		cnt[a - 'a']++;
		mx = max(mx, cnt[a - 'a']);
	}
	cout << mx;

}