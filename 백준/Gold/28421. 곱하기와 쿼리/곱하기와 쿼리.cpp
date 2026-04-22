#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, q;
	cin >> n >> q;
	int arr[10001]{}, orig[100001]{};
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		orig[i] = a;
		arr[a]++;
	}
	for (; q--;) {
		int o, a;
		cin >> o >> a;
		if (o == 2) {
			arr[orig[a]]--;
			orig[a] = 0;
			arr[0]++;
			continue;
		}
		bool fd = 0;
		if (a == 0) {
			if (arr[0] > 1)	cout << 1 << '\n';
			else if (arr[0] == 1 && (n - arr[0]))	cout << 1 << '\n';
			else	cout << 0 << '\n';
			continue;
		}
		for (int i = 1; i <= 10000; i++) {
			if (i > a)	break;
			if (a % i)	continue;
			if (!arr[i])	continue;
			int g = a / i;
			if (g > 10000)	continue;
			if (g < i)	break;
			if ((g == i && arr[g] > 1) || (g != i && arr[g])) {
				fd = 1;
				cout << 1 << '\n';
				break;
			}
		}
		if (!fd)	cout << 0 << '\n';
	}
}