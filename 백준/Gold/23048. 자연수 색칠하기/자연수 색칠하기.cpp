#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[500001]{}, s = 2;
	cin >> N;
	arr[1] = 1;
	for (int i = 2; i * i <= N; i++) {
		if (!arr[i]) {
			for (int j = i; j <= N; j += i)	arr[j] = s;
			s++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!arr[i])	arr[i] = s++;
	}
	cout << s - 1 << '\n';
	for (int i = 1; i <= N; i++)	cout << arr[i] << ' ';
}