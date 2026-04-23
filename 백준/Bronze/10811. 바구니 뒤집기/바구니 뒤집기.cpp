#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, arr[101]{}, a, b;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	arr[i] = i;
	for (; M--;) {
		cin >> a >> b;
		while (a < b)	swap(arr[a++], arr[b--]);
	}
	for (int i = 1; i <= N; i++)	cout << arr[i] << ' ';
}