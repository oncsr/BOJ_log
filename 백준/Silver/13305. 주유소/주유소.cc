#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n, a[100000]{}, b, s = 0, temp = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++)	cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		cin >> b;
		if (!i)	temp = b;
		if (b < temp)	temp = b;
		s += temp * a[i];
	}
	cout << s;
}