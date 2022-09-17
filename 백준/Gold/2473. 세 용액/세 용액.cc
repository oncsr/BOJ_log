#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll abc(ll n) {
	return n < 0 ? (-1)*n : n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<ll> arr;
	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	ll mn = 3000000001;
	ll a, b, c;
	for (int i = 0; i < N - 2; i++) {
		int f = i + 1;
		int g = N - 1;
		ll sum = 0;
		while (f != g) {
			sum = arr[i] + arr[f] + arr[g];
			if (abc(sum) < mn) {
				mn = abc(sum);
				a = arr[i];
				b = arr[f];
				c = arr[g];
			}
			else {
				if (sum > 0)
					g--;
				else
					f++;
			}
		}
	}
	cout << a << ' ' << b << ' ' << c << '\n';
}