#include <iostream>
using namespace std;

int main() {
	int t;	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, s = 0;
		string a, b;
		cin >> n >> a >> b;
		for (int j = 0; j < n; j++)
			if (a[j] != b[j])	s++;
		cout << "Case " << i << ": " << s << '\n';
	}
}