#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int e[10001]{};
	for (int i = 2; i * i <= 10000; i++)
		if (!e[i])
			for (int j = i * i; j <= 10000; j += i)
				e[j] = 1;

	int T, n;
	for (cin >> T; T--;) {
		cin >> n;
		int g = n / 2;
		while (g > 1) {
			if (!e[g] && !e[n - g]) {
				cout << g << ' ' << n - g << '\n';
				break;
			}
			g--;
		}
	}

}