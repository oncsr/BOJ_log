#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int TC;
	for (cin >> TC; TC--;) {
		int n, arr[5]{};
		cin >> n;
		arr[0] += n / 60;
		n -= arr[0] * 60;
		if (n >= 36) {
			arr[0]++;
			arr[2] = 5 - n / 10;
			if (n % 10 > 4)	arr[4] = 10 - (n % 10);
			else {
				arr[2]++;
				arr[3] = n % 10;
			}
		}
		else {
			arr[1] = n / 10;
			if (n % 10 > 5) {
				arr[1]++;
				arr[4] = 10 - (n % 10);
			}
			else	arr[3] = n % 10;
		}
		for (int i = 0; i < 5; i++)	cout << arr[i] << ' ';
		cout << '\n';
	}
}