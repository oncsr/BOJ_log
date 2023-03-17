#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int N;
ll arr[1000000]{};
ll arr1[1000000]{};

bool cmp(ll a, ll b) { return a > b; }

ll task() {
	int s = 0, e = N - 1;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0)	arr1[i] = arr[s++];
		else	arr1[i] = arr[e--];
	}
	ll ans = 0;
	for (int i = 1; i < N; i++)
		ans += abs(arr1[i] - arr1[i - 1]);

	ll cnt = ans;
	for (int i = 0; i < N - 1; i++) {
		int right = i + 1, left = (i ? i - 1 : N - 1);
		cnt -= abs(arr1[i] - arr1[right]);
		cnt += abs(arr1[i] - arr1[left]);
		ans = max(ans, cnt);
	}

	return ans;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);
	ll val1 = task();
	sort(arr, arr + N, cmp);
	ll val2 = task();
	
	cout << max(val1, val2);
	

}