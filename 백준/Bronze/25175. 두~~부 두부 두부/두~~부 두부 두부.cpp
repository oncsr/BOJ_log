#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	long long N, M, K;
	cin >> N >> M >> K;

	for (long long i = 1; i <= N; i++) {
		if ((3 + i - M + N * 100000 - K) % N == 0) {
			cout << i;
			return 0;
		}
	}

}