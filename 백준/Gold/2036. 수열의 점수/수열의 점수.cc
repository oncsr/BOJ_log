#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	
	int arr[100001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	ll sum = 0;
	int pr[2] = { 0 };
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0)
			pr[i % 2] = arr[i];
		else {
			if (arr[i] == 0) {
				if (pr[0] != 0)
					pr[0] = 0;
				break;
			}
			if (pr[0] != 0)
				sum += (ll)pr[0];
			pr[0] = 0;
			break;
		}
		if ((ll)pr[0] * (ll)pr[1] > 0) {
			sum += (ll)pr[0] * (ll)pr[1];
			pr[0] = 0;
			pr[1] = 0;
		}
	}
	if (pr[0] != 0)
		sum += (ll)pr[0];
	pr[0] = 0;
	pr[1] = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] > 0) {
			if (arr[i] == 1) {
				sum += (ll)pr[0];
				sum += (ll)pr[1];
				pr[0] = 0;
				pr[1] = 0;
				sum += (ll)arr[i];
			}
			else
				pr[i % 2] = arr[i];
		}
		else {
			if (pr[0] != 0)
				sum += (ll)pr[0];
			if (pr[1] != 0)
				sum += (ll)pr[1];
			pr[0] = 0;
			pr[1] = 0;
			break;
		}
		if ((ll)pr[0] * (ll)pr[1] > 0) {
			sum += (ll)pr[0] * (ll)pr[1];
			pr[0] = 0;
			pr[1] = 0;
		}
	}
	if (pr[0] != 0)
		sum += (ll)pr[0];
	if (pr[1] != 0)
		sum += (ll)pr[1];
	cout << sum << '\n';
}