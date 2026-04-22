#include <iostream>
using namespace std;

int main() {
	int e[1000001]{};
	for (int i = 2; i * i <= 1000000; i++) {
		if (!e[i]) {
			for (int j = i * i; j <= 1000000; j += i)
				e[j]++;
		}
	}
	int T, n;
	for (cin >> T; T--;) {
		cin >> n;
		int s = 2, ans = 0;
		while (s <= n / 2) {
			if (!e[s] && !e[n - s])	ans++;
			s++;
		}
		cout << ans << '\n';
	}
}