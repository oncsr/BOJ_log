#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int L, N, K, arr[100001]{};
	cin >> L >> N >> K;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	arr[N] = L;
	int s = 1, e = L * 2, m = (s + e) / 2;
	while (s <= e) {
		int cnt = 0, last = 0, temp = -1;
		for (int i = 0; i <= N; i++) {
			if (arr[i] - last > m) {
				if (i == 0) {
					cnt = -1;
					break;
				}
				last = temp;
				if (arr[i] - last > m) {
					cnt = -1;
					break;
				}
				cnt++;
			}
			temp = arr[i];
		}
		if (cnt > K || cnt == -1) {
			if (s == e) {
				cout << m + 1;
				return 0;
			}
			s = m + 1;
		}
		else {
			if (s == e) {
				cout << m;
				return 0;
			}
			e = m;
		}
		m = (s + e) / 2;
	}
}