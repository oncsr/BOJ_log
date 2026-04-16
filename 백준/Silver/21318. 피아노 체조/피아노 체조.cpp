#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, arr[100001]{}, prev = 0;
	cin >> N >> prev;
	for (int i = 1; i < N; i++) {
		int a;
		cin >> a;
		if (prev > a)	arr[i] = 1;
		arr[i] += arr[i - 1];
		prev = a;
	}
	
	int Q;
	for (cin >> Q; Q--;) {
		int x, y;
		cin >> x >> y;
		if (x == y)	cout << "0\n";
		else	cout << arr[y - 1] - arr[x - 1] << '\n';
	}

}