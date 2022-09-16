#include <iostream>
using namespace std;

int main() {
	long long d[91] = { 0,1,1 };
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++)	d[i] = d[i - 1] + d[i - 2];
	cout << d[n];
}