#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a[1000]{}, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)	if (a[i] <= l)	l++;
	cout << l;
}