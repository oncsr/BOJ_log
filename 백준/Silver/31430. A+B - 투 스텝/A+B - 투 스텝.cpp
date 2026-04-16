#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
ll A, B;
string S;

void one() {
	cin >> A >> B;
	A += B;
	string res = "";
	ll d = 26;
	while (A) {
		ll val = (A % d) / (d / 26);
		res = (char)(val + 'a') + res;
		A -= val * (d / 26);
		d *= 26;
	}
	while (res.size() < 13) res = "a" + res;
	cout << res;
}

void two() {
	cin >> S;
	ll res = 0;
	ll d = 1;
	for (int j = S.size() - 1; j >= 0; j--) {
		ll bck = S[j] - 'a';
		res += d * bck;
		d *= 26;
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	if (T == 1) one();
	else		two();

}