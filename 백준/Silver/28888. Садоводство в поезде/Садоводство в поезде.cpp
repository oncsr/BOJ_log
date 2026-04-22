#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, arr[100000]{}, mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n, greater<>());
	for (int i = 0; i < n; i++)	mx = max(mx, arr[i] + i);
	cout << mx;
}