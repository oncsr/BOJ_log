#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	ii arr[10000]{};
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a,b };
	}
	sort(arr, arr + N, greater<ii>());
	int d[10001]{};
	for (int i = 1; i <= 10000; i++)	d[i] = i;
	int s = 0;
	for (int k = 0; k < N; k++) {
		int val = arr[k].first;
		int dead = arr[k].second;
		vector<int> store;
		while (dead != d[dead]) {
			store.push_back(dead);
			dead = d[dead];
		}
		if (dead <= 0)	continue;
		s += val;
		store.push_back(dead);
		for (int i : store)	d[i] = d[dead - 1];
	}
	cout << s;
}