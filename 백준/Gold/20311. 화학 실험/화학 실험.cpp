#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

bool cmp(ii a, ii b) {
	if (a.first == b.first)	return a.second < b.second;
	return a.first > b.first;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K, arr[300001]{}, mx = 0;
	vector<ii> V;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		mx = max(mx, a);
		V.push_back({ a, i + 1 });
	}
	if (mx > (N + 1) / 2)	cout << -1;
	else {
		sort(V.begin(), V.end(), cmp);
		int s = 1;
		for (ii now : V) {
			int id = now.second;
			int cnt = now.first;
			while (cnt--) {
				arr[s] = id;
				s += 2;
				if (s > N)	s = 2;
			}
		}
		for (int i = 1; i <= N; i++)	cout << arr[i] << ' ';
	}
}