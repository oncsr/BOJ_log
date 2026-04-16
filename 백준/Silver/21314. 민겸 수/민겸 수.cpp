#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	auto ch = [](string n) -> string {
		string res = "";
		for (int i = 0; i < n.size(); i++) res += '0';
		if (n.back() == 'M') res[0] = '1';
		else	res[0] = '5';
		return res;
	};

	string s;
	cin >> s;
	string mn = "", mx = "";
	string a = "", b = "";
	for (char i : s) {
		if (i == 'M') {
			a += i;
			b += i;
		}
		else {
			if (a != "")	mn += ch(a);
			mn += "5";
			a = "";
			b += i;
			mx += ch(b);
			b = "";
		}
	}
	if (a != "")	mn += ch(a);
	if (b != "") {
		if (b.back() == 'M') {
			for (int i = 0; i < b.size(); i++)	mx += '1';
		}
		else	mx += ch(b);
	}
	cout << mx << '\n' << mn;

}