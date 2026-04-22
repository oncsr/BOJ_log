#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int arr[1000001]{};
	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] ^= arr[i - 1];
	}
	int ans = 0;
	for (; Q--;) {
		int s, e;
		cin >> s >> e;
		ans ^= arr[e] ^ arr[s - 1];
	}
	cout << ans;

}