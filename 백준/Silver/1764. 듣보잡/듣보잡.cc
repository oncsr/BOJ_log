#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<string, int> M;
	set<string> S;
	int n, m;
	string a;
	for (cin >> n >> m; n--;) {
		cin >> a;
		M[a]++;
	}
	for (; m--;) {
		cin >> a;
		if (M[a])	S.insert(a);
	}
	cout << S.size() << '\n';
	for (string i : S)	cout << i << '\n';	
}