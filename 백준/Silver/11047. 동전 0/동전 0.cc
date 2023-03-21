#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K, s = 0;
	int arr[10]{};
	cin >> N >> K;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	int id = N - 1;
	while (K) {
		while (K < arr[id])	id--;
		s += (K / arr[id]);
		K %= arr[id];
	}
	cout << s;
}