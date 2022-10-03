#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a[100000]{}, mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		mx = max(mx, a[i] * (n - i));
	cout << mx;
}