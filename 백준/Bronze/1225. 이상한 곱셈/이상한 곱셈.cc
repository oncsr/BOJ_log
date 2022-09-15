#include <iostream>
using namespace std;

int main() {
	long long ans = 0;
	string a, b;
	cin >> a >> b;
	for (auto& i : a)
		for (auto& j : b)
			ans += (i - '0') * (j - '0');
	cout << ans << '\n';
}