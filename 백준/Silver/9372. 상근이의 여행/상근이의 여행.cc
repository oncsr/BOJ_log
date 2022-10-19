#include <iostream>
using namespace std;
int main() {
	int T, N, M, a, b;
	for (cin >> T; T--;) {
		for (cin >> N >> M; M--;)	cin >> a >> b;
		cout << N - 1 << '\n';
	}
}