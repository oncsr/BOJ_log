#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		ll cnt = 0, major = 0;
		ll arr[100000]{};
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			if (!cnt)	cnt++, major = arr[i];
			else if (major == arr[i])	cnt++;
			else	cnt--;
		}
		cnt = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] == major)	cnt++;
		}
		if (cnt > N / 2)	cout << major << '\n';
		else	cout << "SYJKGW\n";
	}
}