#include <bits/stdc++.h>
#include <regex>
using namespace std;
using ll = unsigned long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string check = "aeiouAEIOU";
	string a;
	for (getline(cin, a); a != "#"; getline(cin, a)) {
		int s = 0;
		for (char i : a) {
			bool exist = 0;
			for (char j : check)	exist |= i == j;
			s += exist;
		}
		cout << s << '\n';
	}

}