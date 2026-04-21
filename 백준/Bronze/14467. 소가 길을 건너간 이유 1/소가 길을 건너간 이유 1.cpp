#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, cnt = 0;
	vector<int> arr(11, -1);
	for (cin >> n; n--;) {
		int a, b;
		cin >> a >> b;
		if (arr[a] == -1)	arr[a] = b;
		else {
			if (arr[a] == b)	continue;
			cnt++;
			arr[a] = b;
		}
	}
	cout << cnt;
}