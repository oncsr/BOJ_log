#include <iostream>
#include <algorithm>
using namespace std;

using iii = pair<pair<int, int>, pair<int, int> >;
bool cmp(iii a, iii b) {
	if (a.first.first == b.first.first) {
		if (a.first.second == b.first.second) {
			return a.second.first < b.second.first;
		}
		return a.first.second < b.first.second;
	}
	return a.first.first > b.first.first;
}

int main() {
	int n;
	iii arr[10000]{};
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = { {a,b},{c,i + 1} };
	}
	sort(arr, arr + n, cmp);
	cout << arr[0].second.second;
}