#include <iostream>
using namespace std;
using ii = pair<int, int>;

int main() {
	int N, T;
	ii arr[1000]{};
	cin >> N >> T;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		sum1 += arr[i].first;
		sum2 += arr[i].second;
	}
	if (sum1 > T || sum2 < T) {
		cout << -1;
		return 0;
	}
	int s = 1, e = T, m = (s + e) / 2;
	while (s <= e) {
		int left = 0, right = 0, sum = 0;
		for (int i = 0; i < N; i++) {
			if (m < arr[i].first)	left++;
			else	sum += min(arr[i].second, m);
		}
		if (left) {
			if (s == e) {
				cout << -1;
				return 0;
			}
			s = m + 1;
		}
		else {
			if (sum >= T) {
				if (s == e) break;
				e = m;
			}
			else {
				if (s == e) {
					cout << -1;
					return 0;
				}
				s = m + 1;
			}
		}
		m = (s + e) / 2;
	}
	cout << m;
}