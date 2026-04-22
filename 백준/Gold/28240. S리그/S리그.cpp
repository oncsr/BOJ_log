#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, mn = -1000000000, mx = 1000000000;
	int a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	int arr[4] = { a,b,c,d };
	sort(arr, arr + 4);
	a = arr[0], b = arr[1], c = arr[2], d = arr[3];
	for (int i = 1; i <= a; i++)	cout << -a + i << ' ' << mn << '\n';
	for (int i = 1; i <= b - a; i++)	cout << mx << ' ' << mx - (b - a) + i << '\n';
	for (int i = 1; i <= d - b - 1; i++)	cout << d - b - 1 - i << ' ' << 0 << '\n';
	for (int i = 0; i <= n - d; i++)	cout << mn << ' ' << mx - i << '\n';
}