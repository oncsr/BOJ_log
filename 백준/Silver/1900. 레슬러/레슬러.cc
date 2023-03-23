#include <iostream>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

bool cmp(pair<ii, int> a, pair<ii, int> b) {
	return a.first.first + a.first.second * b.first.first > b.first.first + b.first.second * a.first.first;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	pair<ii, int> arr[10000]{};
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first.first >> arr[i].first.second;
		arr[i].second = i + 1;
	}
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++) {
		cout << arr[i].second << '\n';
	}
}