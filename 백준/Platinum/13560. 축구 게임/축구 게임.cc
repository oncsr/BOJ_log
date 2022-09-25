#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int zcnt = 0, fcnt = 0, sum = 0, ch = n * (n - 1) / 2;
	int arr[10001] = { 0 };
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 0)	zcnt++;
		if (a == n - 1)	fcnt++;
		arr[a]++;
		sum += a;
	}
	if ((sum != ch) || (zcnt > 1) || (fcnt > 1))
		cout << "-1\n";
	else {
		bool fail = false;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] == 0)	break;
			if (arr[i] > 1) {
				fail = true;
				break;
			}
		}
		if (fail)	cout << "-1\n";
		else	cout << "1\n";
	}
}