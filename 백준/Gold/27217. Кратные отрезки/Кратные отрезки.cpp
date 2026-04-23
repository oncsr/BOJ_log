#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	map<ll, ll> arr2;
	ll sum = 0, ans = 0, t = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		sum += a;
		if (sum % M == 0) {
			t++;
			ans += t;
		}
		else {
			ans += arr2[sum % M];
			arr2[sum % M]++;
		}
	}
	cout << ans;
}