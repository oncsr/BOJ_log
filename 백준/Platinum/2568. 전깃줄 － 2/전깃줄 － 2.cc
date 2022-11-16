#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ii arr[100000]{};
	int n, d[100000]{};
	int r[500001]{};
	int r2[500001]{};
	for (int i = 0; i < 500001; i++)	r2[i] = 2;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		r2[arr[i].first] = 1;
		r[arr[i].second] = arr[i].first;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		a.push_back(arr[i].second);
	}
	vector<int> K;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int id = lower_bound(K.begin(), K.end(), a[i]) - K.begin();
		if (id == K.size())
			K.push_back(a[i]);
		else K[id] = a[i];
		ans.push_back(id);
	}
	cout << n - K.size() << '\n';
	int mx = K.size() - 1;
	vector<int> V;
	for (int i = n - 1; i >= 0; i--) {
		if (ans[i] == mx) {
			r2[r[a[i]]] = 0;
			mx--;
		}
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < 500001; i++)
		if (r2[i] == 1)	cout << i << '\n';
}