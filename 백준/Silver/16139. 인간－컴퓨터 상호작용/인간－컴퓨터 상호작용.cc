#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int> > V(200001);
	V[0] = vector<int>(26, 0);
	string a;
	cin >> a;
	for (int i = 1; i <= a.size(); i++) {
		vector<int> temp = V[i - 1];
		temp[a[i - 1] - 'a']++;
		V[i] = temp;
	}
	int Q;
	for (cin >> Q; Q--;) {
		char o;
		int l, r;
		cin >> o >> l >> r;
		l++, r++;
		cout << V[r][o - 'a'] - V[l - 1][o - 'a'] << '\n';
	}

}