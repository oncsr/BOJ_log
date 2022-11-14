#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, b;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		cout << "Case " << i << ": " << a - 1 << ' ';
		for (; a--;) {
			cin >> b;
			cout << b * (a + 1) << ' ';
		}
		cout << '\n';
		cin >> b;
	}
}