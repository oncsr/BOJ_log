#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, arr[100001]{}, a, b;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (; M--;) {
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << '\n';
	}
}