#include <iostream>
using namespace std;

int main() {
	int n, d[41] = { 0,1,1 };
	for (int i = 3; i <= 40; i++)
		d[i] = d[i - 1] + d[i - 2];
	cin >> n;
	cout << d[n] << ' ' << n - 2;
}