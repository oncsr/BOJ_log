#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int n, m, i = 0, arr[2000000]{};
	cin >> n >> m;
	for (; i < n; i++)	cin >> arr[i];
	for (; i < n + m; i++)	cin >> arr[i];
	sort(arr, arr + n + m);
	for (int i = 0; i < n + m; i++)	cout << arr[i] << ' ';
}