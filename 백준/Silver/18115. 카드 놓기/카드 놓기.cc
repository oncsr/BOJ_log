#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, a;
	cin >> n;
	int s = 1, ss = 2, e = n;
	int arr[1000001]{};
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {
			arr[s] = n - i;
			while (arr[s])	s++;
			while (arr[ss] || s == ss)	ss++;
		}
		else if (a == 3) {
			arr[e] = n - i;
			while (arr[e])	e--;
		}
		else {
			arr[ss] = n - i;
			while (arr[ss] || s == ss)	ss++;
		}
	}
	for (int i = 1; i <= n; i++)	cout << arr[i] << ' ';

}