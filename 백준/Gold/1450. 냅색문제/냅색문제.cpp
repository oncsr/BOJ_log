#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int arr[30]{}, n, C;
vector<ll> result1;
vector<ll> result2;

void recur(int pos, ll value, int type) {
	if (type == 1 && pos == n / 2) {
		result1.push_back(value);
		return;
	}
	if (type == 2 && pos == n) {
		result2.push_back(value);
		return;
	}
	recur(pos + 1, value + arr[pos], type);
	recur(pos + 1, value, type);
}

int main() {
	cin >> n >> C;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	recur(0, 0, 1);
	recur(n / 2, 0, 2);
	sort(result2.begin(), result2.end());
	int ans = 0;
	for (int i = 0; i < result1.size(); i++) {
		ll G = C - result1[i];
		ans += (upper_bound(result2.begin(), result2.end(), G) - result2.begin());
	}
	cout << ans;
}