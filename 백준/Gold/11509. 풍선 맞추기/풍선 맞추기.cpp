#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	int arrow[1000001]{};
	int ans = 0;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (arrow[a]) {
			arrow[a]--;
			arrow[a - 1]++;
		}
		else {
			ans++;
			arrow[a - 1]++;
		}
	}
	cout << ans;

}