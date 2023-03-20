#include <iostream>
using namespace std;

int mx = 0;
int N, K;
int arr[20]{};

void R(int pos, int now, int val) {
	if (pos == N) {
		mx = max(mx, val);
		return;
	}

	// arr[pos]를 먹지 않는 경우

	R(pos + 1, now, val);
	
	// 먹는 경우

	now += arr[pos];
	if (now >= K) {
		val += (now - K);
		now = 0;
	}
	R(pos + 1, now, val);

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	R(0, 0, 0);
	cout << mx;
}