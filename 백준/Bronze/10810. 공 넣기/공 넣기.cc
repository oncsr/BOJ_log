#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, arr[100]{}, a, b, c;
	for (cin >> N >> M; M--;) {
		cin >> a >> b >> c;
		for (int i = a - 1; i < b; i++)	arr[i] = c;
	}
	for (int i = 0; i < N; i++)	cout << arr[i] << ' ';
}