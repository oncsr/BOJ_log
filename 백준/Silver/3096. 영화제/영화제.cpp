#include <iostream>
#include <bitset>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	bitset<1000> B[1000];
	int N, M;
	for (cin >> N >> M; M--;) {
		int a, b;
		cin >> a >> b;
		B[--a].set(--b);
	}

	long long ans = 0;
	for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) {
		long long cnt = (B[i] & B[j]).count();
		ans += cnt * (cnt - 1) / 2;
	}
	cout << ans;

}