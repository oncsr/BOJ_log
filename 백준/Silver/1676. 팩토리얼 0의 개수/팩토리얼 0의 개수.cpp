#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int T = i;
		while (T % 5 == 0)	ans++, T /= 5;
	}
	cout << ans;
}