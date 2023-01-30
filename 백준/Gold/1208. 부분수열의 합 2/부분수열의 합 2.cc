#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[40]{}, N, S;
vector<int> res1;
vector<int> res2;

void R(int pos, int value, int cnt, int type) {
	if (type == 1 && pos == N / 2) {
		if (cnt)	res1.push_back(value);
		return;
	}
	if (type == 2 && pos == N) {
		if (cnt)	res2.push_back(value);
		return;
	}
	R(pos + 1, value + arr[pos], cnt + 1, type);
	R(pos + 1, value, cnt, type);
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	R(0, 0, 0, 1);
	R(N / 2, 0, 0, 2);
	long long ans = 0;
	for (int i : res1)
		if (i == S)
			ans++;
	sort(res2.begin(), res2.end());
	ans += upper_bound(res2.begin(), res2.end(), S) - lower_bound(res2.begin(), res2.end(), S);
	for (int i = 0; i < res1.size(); i++) {
		int G = S - res1[i];
		ans += upper_bound(res2.begin(), res2.end(), G) - lower_bound(res2.begin(), res2.end(), G);
	}
	cout << ans;
}