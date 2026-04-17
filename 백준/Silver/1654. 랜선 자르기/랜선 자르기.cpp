#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int K, N;
	cin >> K >> N;
	vector<int> lan(K);
	for (int& i : lan)	cin >> i;

	unsigned int low = 1, high = (1 << 31) - 1, mid = (low + high + 1) / 2;
	while (low < high) {
		int cnt = 0;
		for (int& i : lan)	cnt += i / mid;

		if (cnt < N)	high = mid - 1;
		else	low = mid;
		mid = (low + high + 1) / 2;
	}
	cout << mid;

}