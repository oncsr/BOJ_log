#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	map<string, int> A;
	map<string, int> B;
	int n, m, s = 0;
	cin >> n >> m;
	string a;
	set<string> S;
	set<string> G;
	while (n--) {
		cin >> a;
		A[a] = 1;
		S.insert(a);
	}
	while (m--) {
		cin >> a;
		B[a] = 1;
		S.insert(a);
	}
	for (auto& i : S) {
		if (A[i] && B[i]) {
			s++;
			G.insert(i);
		}
	}
	cout << s << '\n';
	for (auto& i : G)	cout << i << '\n';
}