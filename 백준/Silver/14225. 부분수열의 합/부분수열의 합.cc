#include <iostream>
using namespace std;

int arr[20]{}, N;
bool check[2000001]{};

void recur(int pos, int value) {
	if (pos == N) {
		check[value] = 1;
		return;
	}
	recur(pos + 1, value + arr[pos]);
	recur(pos + 1, value);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	recur(0, 0);
	for (int i = 1; i <= 100000 * N; i++) {
		if (!check[i]) {
			cout << i;
			break;
		}
	}
}