#include <iostream>
using namespace std;

int arr[10]{}, ans = 0;

void test(int pos, int now, int prev, int score) {
	if (pos == 9) {
		if (score >= 5)	ans++;
		return;
	}
	for (int i = 1; i <= 5; i++) {
		if (prev == now && now == i)	continue;
		test(pos + 1, i, now, score + (int)(i == arr[pos + 1]));
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 10; i++)	cin >> arr[i];
	for (int i = 1; i <= 5; i++)	test(0, i, -1, (int)(i == arr[0]));
	cout << ans;
}