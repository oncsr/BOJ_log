#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int &i : arr)	cin >> i;
	int ans = 0, mx = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (arr[i] > mx)	ans++, mx = arr[i];
	}
	cout << ans;

}