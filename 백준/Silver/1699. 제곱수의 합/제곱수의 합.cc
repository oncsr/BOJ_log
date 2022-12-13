#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int n, d[100001] = { 0,1,2,3 };
	for (int i = 2; i * i <= 100000; i++) {
		d[i * i] = 1;
		for (int j = i * i + 1; j <= 100000; j++) {
			if (!d[j])	d[j] = d[i * i] + d[j - i * i];
			else	d[j] = min(d[j], d[i * i] + d[j - i * i]);
		}
	}
	cin >> n;
	cout << d[n];
}