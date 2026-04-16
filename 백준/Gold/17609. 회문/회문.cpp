#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	for (cin >> T; T--;) {
		string a;
		cin >> a;

		int s = 0, e = a.size() - 1;
		bool is_palindrome = 1;
		int almost = 2;
		while (s < e) {
			if (a[s] != a[e]) {
				is_palindrome = 0;
				// 유사 회문 검사
				int ss = s + 1, ee = e;

				while (ss < ee) {
					if (a[ss] != a[ee]) {
						almost--;
						break;
					}
					ss++, ee--;
				}
				
				ss = s, ee = e - 1;
				while (ss < ee) {
					if (a[ss] != a[ee]) {
						almost--;
						break;
					}
					ss++, ee--;
				}
				break;
			}
			s++, e--;
		}
		if (is_palindrome) {
			cout << "0\n";
			continue;
		}
		cout << (almost ? "1\n" : "2\n");


	}

}