#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll arr[4]{};
vector<char> ans;



int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	char q;
	cin >> arr[0] >> q >> arr[1] >> q >> arr[2] >> q >> arr[3];
	string ch = "+*-";
	vector<string> C;
	for (ll i = 0; i < 3; i++) {
		char a = ch[i];
		for (ll j = 0; j < 3; j++) {
			char b = ch[j];
			string c1 = "=";
			c1 += a;
			c1 += b;
			string c2 = "=";
			c2 = a + c2;
			c2 += b;
			string c3 = "=";
			c3 = b + c3;
			c3 = a + c3;
			C.push_back(c1);
			C.push_back(c2);
			C.push_back(c3);
		}
	}
	for (string i : C) {
		if (i[1] == '*') {
			if (i[0] == '-') {
				ll L = arr[0] - arr[1] * arr[2];
				ll R = arr[3];
				if (L == R) {
					cout << arr[0] << i[0] << arr[1] << i[1] << arr[2] << i[2] << arr[3];
					return 0;
				}
				continue;
			}
			if (i[0] == '+') {
				ll L = arr[0] + arr[1] * arr[2];
				ll R = arr[3];
				if (L == R) {
					cout << arr[0] << i[0] << arr[1] << i[1] << arr[2] << i[2] << arr[3];
					return 0;
				}
				continue;
			}
		}
		else if (i[2] == '*') {
			if (i[0] == '=') {
				if (i[1] == '+') {
					ll L = arr[0];
					ll R = arr[1] + arr[2] * arr[3];
					if (L == R) {
						cout << arr[0] << i[0] << arr[1] << i[1] << arr[2] << i[2] << arr[3];
						return 0;
					}
					continue;
				}
				if (i[1] == '-') {
					ll L = arr[0];
					ll R = arr[1] - arr[2] * arr[3];
					if (L == R) {
						cout << arr[0] << i[0] << arr[1] << i[1] << arr[2] << i[2] << arr[3];
						return 0;
					}
					continue;
				}
			}
		}
		ll L = arr[0], R = 0, j = 0;
		for (; i[j] != '='; j++) {
			if (i[j] == '+')	L = L + arr[j + 1];
			if (i[j] == '*')	L = L * arr[j + 1];
			if (i[j] == '-')	L = L - arr[j + 1];
		}
		R = arr[++j];
		for (; j < 3; j++) {
			if (i[j] == '+')	R = R + arr[j + 1];
			if (i[j] == '*')	R = R * arr[j + 1];
			if (i[j] == '-')	R = R - arr[j + 1];
		}
		if (L == R) {
			cout << arr[0] << i[0] << arr[1] << i[1] << arr[2] << i[2] << arr[3];
			return 0;
		}
	}
	cout << "EI SAA";
}