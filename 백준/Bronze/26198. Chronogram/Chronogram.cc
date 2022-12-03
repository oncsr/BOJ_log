#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t, arr[300]{}, g = 1;
	char e;
	arr[67] = 100, arr[68] = 500, arr[73] = 1, arr[76] = 50;
	arr[77] = 1000, arr[86] = 5, arr[88] = 10;
	cin >> t >> e;
	while (t--) {
		int s = 0;
		if (g)	g = 0, s += arr[e];
		string a;
		getline(cin, a);
		for (char i : a)	s += arr[i];
		cout << s << '\n';
	}
}