#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

using ll = long long;
using pl = pair<ll, ll>;

bool sec_cmp(pl a, pl b) {
	if (a.second == b.second)	return a.first > b.first;
	return a.second > b.second;
}

struct cmp {
	bool operator()(pl a, pl b) {
		int sa = a.first + a.second, sb = b.first + b.second;
		if (sa == sb && a.first == b.first)	return a.second < b.second;
		if (sa == sb)	return a.first < b.first;
		return sa < sb;
	}
};

struct cmp2 {
	bool operator()(pl a, pl b) {
		if (a.second == b.second)	return a.first < b.first;
		return a.second < b.second;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	pl arr[80001]{};
	for (int i = 0; i < N; i++)	cin >> arr[i].first;
	for (int i = 0; i < N; i++)	cin >> arr[i].second;
	sort(arr, arr + N, sec_cmp);
	priority_queue<pl, vector<pl>, cmp> B;
	priority_queue<pl> EX;
	ll SA = 0, SB = 0;
	int pos = 0;
	for (; pos < K; pos++)	B.push(arr[pos]), SB += arr[pos].second;
	ll A_select[80002]{};
	for (int i = N - 1; i >= pos; i--) {
		EX.push(arr[i]);
		if (i < 2 * K) {
			A_select[i] = A_select[i + 1] + EX.top().first;
			EX.pop();
		}
	}
	ll mx = A_select[pos] - SB;

	pos = K;
	while (pos < 2 * K) {
		SB += arr[pos].second;
		B.push(arr[pos]);
		SB -= B.top().second;
		SA += B.top().first;
		B.pop();
		mx = max(mx, SA + A_select[pos + 1] - SB);
		pos++;
	}
	cout << mx;

}