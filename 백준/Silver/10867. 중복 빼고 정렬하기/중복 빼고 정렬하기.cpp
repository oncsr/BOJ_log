#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a;	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i : arr)	cout << i << ' ';
}