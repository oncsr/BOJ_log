#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int ans = 0, k=0;
	for (int i = 0; i < a.size(); i++) {
		if (k >= b.size()) {
			k = 0;
			ans++;
		}
		if (a[i] == b[k++])	continue;
		else {
			i -= (k - 1);
			k = 0;
			continue;
		}
	}
	if (k == b.size())	ans++;
	cout << ans;
}