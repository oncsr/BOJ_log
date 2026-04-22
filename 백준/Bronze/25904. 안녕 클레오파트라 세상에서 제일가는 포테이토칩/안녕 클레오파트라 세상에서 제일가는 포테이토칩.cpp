#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, X;
	cin >> N >> X;
	int arr[100]{};
	for (int i = 0; i < N; i++)	cin >> arr[i];
	int pos = 0;
	while (X <= arr[pos]) {
		pos = (pos + 1) % N;
		X++;
	}
	cout << pos + 1;
}