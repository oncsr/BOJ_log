#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	int arr[100000]{}, cnt[1000001]{};
	for (int i = 0; i < N; i++)	cin >> arr[i], cnt[arr[i]]++;
	
	for (int i = 0; i < N; i++) {
		int res = -1;
		for (int j = 1; j * j <= arr[i]; j++) {
			if (arr[i] % j)	continue;
			res += cnt[j];
			if (j * j == arr[i])	break;
			res += cnt[arr[i] / j];
		}
		cout << res << '\n';
	}

}