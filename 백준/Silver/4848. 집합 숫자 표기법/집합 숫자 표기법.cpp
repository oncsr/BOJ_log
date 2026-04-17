#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string num[16]{};
	map<string, int> M;
	num[0] = "{}";
	M["{}"] = 0;
	for (int i = 1; i <= 15; i++) {
		num[i] = "{";
		for (int j = 0; j < i; j++) {
			num[i] += num[j];
			num[i] += ",";
		}
		num[i].pop_back();
		num[i] += "}";
		M[num[i]] = i;
	}
	
	int T;
	for (cin >> T; T--;) {
		string a, b;
		cin >> a >> b;
		cout << num[M[a] + M[b]] << '\n';
	}

}