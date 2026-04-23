#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	ll arr[300000]{};
	ll S1 = 0, S2 = 0, S3 = 0, S4 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		// i가 홀수이면
		if (i % 2) {
			S2 += arr[i] * ((ll)i + 1);
			S4 += arr[i];
		}
		else {
			S1 += arr[i] * ((ll)i + 1);
			S3 += arr[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (n % 2 == 0) {
			if (i == 0)	cout << S1 - S2 << ' ';
			else {
				ll temp1 = S2, temp2 = S1 + (ll)n * arr[i - 1];
				if (i % 2) {
					temp1 -= S4, temp2 -= S3;
				}
				else {
					temp1 -= S3, temp2 -= S4;
				}
				cout << temp1 - temp2 << ' ';
				S1 = temp1, S2 = temp2;
			}
		}
		else {
			if (i == 0)	cout << S1 - S2 << ' ';
			else {
				ll temp1 = S2 + (ll)n * arr[i - 1];
				ll temp2 = S1;
				if (i % 2) {
					temp1 -= S4, temp2 -= S3;
					S4 += arr[i - 1], S3 -= arr[i - 1];
				}
				else {
					temp1 -= S3, temp2 -= S4;
					S3 += arr[i - 1], S4 -= arr[i - 1];
				}

				cout << temp1 - temp2 << ' ';
				S1 = temp1, S2 = temp2;
			}
		}
	}
}