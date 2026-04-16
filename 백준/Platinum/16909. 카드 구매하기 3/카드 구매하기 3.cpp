#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<int> arr;

vector<int> process(bool is_left, bool is_asc) {
	vector<int> idx(N);
	iota(idx.begin(), idx.end(), 0);
	if (!is_left) {
		reverse(idx.begin(), idx.end());
	}

	vector<int> temp = arr;
	vector<int> ret(N);
	stack<pair<int, int>> st;
	st.emplace(is_asc ? 0 : 1234567, is_left ? -1 : N);
	for (int i : idx) {
		while (is_asc
			? (is_left ? st.top().first > temp[i] : st.top().first >= temp[i])
			: (is_left ? st.top().first < temp[i] : st.top().first <= temp[i])) {
			st.pop();
		}
		ret[i] = st.top().second;
		st.emplace(temp[i], i);
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	arr.resize(N);
	for (int& i : arr) cin >> i;

	vector<int> asc_le = process(true, true);
	vector<int> asc_ri = process(false, true);
	vector<int> desc_le = process(true, false);
	vector<int> desc_ri = process(false, false);

	ll ans = 0;
	for (ll i = 0; i < N; i++) {
		ans -= (i - asc_le[i]) * (asc_ri[i] - i) * arr[i];
		ans += (i - desc_le[i]) * (desc_ri[i] - i) * arr[i];
	}
	cout << ans;

}