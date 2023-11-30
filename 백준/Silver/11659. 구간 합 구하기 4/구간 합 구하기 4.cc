#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int arr[100001];
	int s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (i != 0)
			arr[i] = arr[i - 1] + s;
		else
			arr[i] = s;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a - 2 == -1)
			cout << arr[b - 1] << '\n';
		else
			cout << arr[b - 1] - arr[a - 2] << '\n';
	}
}