#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

bool cmp(ii a, ii b) {
	if (a.first == b.first)	return a.second < b.second;
	return a.first > b.first;
}

int main() {
	int n;
	ii arr[66]{};
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n, cmp);
	int s = 0, c = arr[4].first;
	for (int i = 5; i < n; i++) {
		if (c == arr[i].first)	s++;
		else	break;
	}
	cout << s;
}