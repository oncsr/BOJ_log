#include <iostream>
#include <bitset>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	ll one = 0, l1 = 0, two = 0, l2 = 0;
	for (ll i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a & 1) {
			one += i - l1;
			l1++;
		}
		else {
			two += i - l2;
			l2++;
		}
	}
	cout << min(one, two);
}