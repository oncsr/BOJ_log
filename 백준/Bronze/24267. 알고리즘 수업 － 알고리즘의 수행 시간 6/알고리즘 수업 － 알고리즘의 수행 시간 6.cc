#include <iostream>
using namespace std;
int main() {
	long long n, ans = 0;
	cin >> n;
	while (n-- > 1)
		ans += n * (n - 1) / 2;
	cout << ans << "\n3";
}