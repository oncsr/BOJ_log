#include <iostream>
using namespace std;

int main() {
	int n, m, mx1 = -1, mx2 = -1, p = 0, q = 0, id1 = 0, id2 = 0, id3 = 0;
	cin >> n >> m;
	int a[100000]{};
	int b[100000]{};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > mx1) {
			mx1 = a[i];
			id1 = i;
			id3 = i;
		}
		else if (a[i] == mx1) {
			id3 = i;
		}
		p += a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (b[i] > mx2) {
			mx2 = b[i];
			id2 = i;
		}
		else if (b[i] == mx2) id2 = i;
	}
	p += mx1 * (m - 1);
	q += (id1 + 1) * b[0];
	if (m == 1) {
		q = b[0] * n;
	}
	else if (n == 1) {
		q = 0;
		for (int i = 0; i < m; i++)q += b[i];
	}
	else {
		if (!id2)	q += (id3 - id1) * mx2;
		else	q += (id3 - id1 + 1) * mx2;
		if (id2 == m - 1)	q += (n - id3 - 1) * b[m - 1];
		else	q += (n - id3) * b[m - 1];
		for (int i = 0; i < m; i++) {
			if (i != 0 && i != id2 && i != m - 1)	 q += b[i];
		}
	}
	long long ans = 1000000000;
	cout << ans * p + q;

}