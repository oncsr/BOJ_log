#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a[100000]{}, s = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	s += a[n - 1];
	for (int i = 0; i < (n-1) / 2; i++)
		s += a[n - 2 - i] - a[i];
	cout << s;
}