#include <iostream>
using namespace std;

int main() {
	int n, k, d[100]{}, j = 0, a;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		j = 0;
		if (!d[j])	d[j] = a;
		else if (a > d[j])	d[j] = a;
		else {
			while (j < k && d[j] && a <= d[j]) {
				j++;
			}
			if (j >= k)	break;
			d[j] = a;
		}
	}
	if (j >= k)	cout << "NO";
	else	cout << "YES";
}