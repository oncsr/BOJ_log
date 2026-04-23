#include <iostream>
using namespace std;

int main() {
	int n, k, d[1000001]{}, a;
	for (int i = 1; i <= 1000000; i *= 2) {
		d[i]++;
		for (int j = i + 1; j <= 1000000; j++)
			d[j] = (d[j] + d[j - i]) % 1000000000;
	}
	cin >> k;
	cout << d[k];
}