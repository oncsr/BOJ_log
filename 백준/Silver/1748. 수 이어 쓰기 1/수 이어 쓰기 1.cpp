#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long N, ans = 0, g = 1, i = 1;
	cin >> N;
	for (; i < (long long)log10(N) + 1; i++) {
		if (i == 1)	ans += 9;
		else	ans += g * 9 * i;
		g *= 10;
	}
	ans += (N - g + 1) * i;
	cout << ans;
}