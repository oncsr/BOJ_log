#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int binary_search(int start, int end, int num) {
	int mid = (end - start) / 2;
	if (end == start) {
		if (v[end] == num)
			return 1;
		else
			return 0;
	}
	else {
		if (v[start+mid] == num)
			return 1;
		else if (v[start+mid] > num)
			return binary_search(start, end - mid-1, num);
		else
			return binary_search(start + mid + 1, end, num);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;
		cout << binary_search(0, v.size()-1, b) << '\n';
	}
}