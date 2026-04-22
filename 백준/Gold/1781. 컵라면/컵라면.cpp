#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	ii ramen[200000]{};
	// value, deadline
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		ramen[i] = { b,a };
	}
	sort(ramen, ramen + N, greater<ii>());
	int arr[200001]{};
	for (int i = 1; i <= N; i++)	arr[i] = i;
	int s = 0;
	for (int k = 0; k < N; k++) {
		int dead = ramen[k].second;
		int val = ramen[k].first;
		vector<int> store;
		while (dead != arr[dead]) {
			store.push_back(dead);
			dead = arr[dead];
		}
		if (dead <= 0)	continue;
		s += val;
		store.push_back(dead);
		for (int i : store)	arr[i] = arr[dead - 1];
	}
	cout << s;
}