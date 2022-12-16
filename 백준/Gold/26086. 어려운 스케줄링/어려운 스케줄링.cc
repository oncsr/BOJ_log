#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q, k, last = 0, a, b;
	cin >> N >> Q >> k;
	deque<int> D;
	ii query[100000]{};
	for (int i = 0; i < Q; i++) {
		cin >> a;
		if (!a)	cin >> b;
		else	b = a;
		if (a == 1)	last = i;
		query[i] = { a,b };
	}
	vector<int> arr;
	bool re = false;
	for (int i = 0; i < Q; i++) {
		if (i < last) {
			if (!query[i].first)
				arr.push_back(query[i].second);
		}
		else if (i == last) {
			if (i == 0) {
				D.push_back(query[i].second);
			}
			else {
				sort(arr.begin(), arr.end());
				for (int t : arr)	D.push_back(t);
				re = true;
			}
		}
		else {
			if (!query[i].first) {
				if (re)	D.push_front(query[i].second);
				else	D.push_back(query[i].second);
			}
			else {
				re ^= 1;
			}
		}
	}
	k--;
	if (!re) {
		while (k--)	D.pop_back();
		cout << D.back();
	}
	else {
		while (k--)	D.pop_front();
		cout << D.front();
	}
}