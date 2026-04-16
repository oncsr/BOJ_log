#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> arr;
vector<int> st;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	arr.resize(N);
	for (auto& [x, y] : arr) {
		cin >> x >> y;
		if (x < y) {
			swap(x, y);
		}
	}
	sort(arr.begin(), arr.end());
 
	for (auto [_, y] : arr) {
		auto p = lower_bound(st.begin(), st.end(), -y);
		if (p == st.end()) {
			st.push_back(-y);
		}
		else {
			*p = -y;
		}
	}

	cout << st.size();

}