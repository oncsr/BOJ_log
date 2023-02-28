#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int n, m, a, arr[1000000]{}, id = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	for (int i = 0; i < m; i++) {
		cin >> a;
		while (a > arr[id] && id < n)	cout << arr[id++] << ' ';
		cout << a << ' ';
	}
	while (id < n)	cout << arr[id++] << ' ';
}