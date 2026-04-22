#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		string S;
		cin >> S;
		string Sp = "";
		for (int i = 0; i < (S.size() + 2) / 3; i++)	Sp += S[i];
		string Rs = Sp;
		reverse(Rs.begin(), Rs.end());
		string TRs = Rs;
		TRs = Rs.substr(1, Rs.size());
		string Ts = Sp.substr(1, Sp.size());
		if (Sp + Rs + Sp == S) {
			cout << "1\n";
			continue;
		}
		if (Sp + TRs + Sp == S) {
			cout << "1\n";
			continue;
		}
		if (Sp + Rs + Ts == S) {
			cout << "1\n";
			continue;
		}
		if (Sp + TRs + Ts == S) {
			cout << "1\n";
			continue;
		}
		cout << "0\n";
	}

}