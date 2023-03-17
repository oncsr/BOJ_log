#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	map<int, string> M1;
	map<string, int> M2;
	string a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		M1[i] = a;
		M2[a] = i;
	}
	for (; m--;) {
		cin >> a;
		if (a[0] >= 48 && a[0] <= 57)	cout << M1[stoi(a)] << '\n';
		else	cout << M2[a] << '\n';
	}
}