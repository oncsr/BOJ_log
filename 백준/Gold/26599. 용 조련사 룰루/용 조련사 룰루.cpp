#include <iostream>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

bool cmp(ii a, ii b) {
	if (a.first == b.first)	return a.second < b.second;
	return a.first > b.first;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	ii arr[1000000]{};
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = { a,i + 1 };
	}
	sort(arr, arr + n, cmp);
	if (n > 3) {
		if (arr[2].first + m < arr[1].first || arr[3].first + m < arr[2].first) {
			cout << "NO";
		}
		else {
			cout << "YES\n";
			for (int i = 2; i < n; i++)	cout << arr[i].second << ' ';
			cout << arr[1].second << ' ' << arr[0].second;
		}
	}
	else {
		if (n == 3) {
			if (arr[2].first + m < arr[1].first)	cout << "NO";
			else {
				cout << "YES\n";
				for (int i = 0; i < n; i++)	cout << arr[i].second << ' ';
			}
		}
		else {
			cout << "YES\n";
			for (int i = 0; i < n; i++)	cout << arr[i].second << ' ';
		}
	}
}