#include <iostream>
using namespace std;

int main() {
	int n, a[1001]{}, d[1001]{};
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (i != 1 && d[i] == 0)	continue;
		for (int j = i + 1; j <= i + a[i] && j <= n; j++)
			d[j] = (d[j] ? min(d[j], d[i] + 1) : d[i] + 1);
	}
	cout << (d[n] ? d[n] : (n == 1 ? 0 : -1));
}