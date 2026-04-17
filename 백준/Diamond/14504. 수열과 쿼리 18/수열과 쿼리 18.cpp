#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, sq;
int arr[100001]{};
vector<int> bck[501]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	sq = sqrt(N);
	int id = 1;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		bck[id].push_back(arr[i]);
		if (i % sq == 0) {
			sort(bck[id].begin(), bck[id].end());
			id++;
		}
	}
	sort(bck[id].begin(), bck[id].end());

	int Q;
	for (cin >> Q; Q--;) {
		int o, i, j, k;
		cin >> o >> i;
		int s = (i - 1) / sq + 1;
		if (o == 1) {
			cin >> j >> k;
			int e = (j - 1) / sq + 1;
			int ans = 0;
			for (int x = i; x <= min(j, s * sq); x++)	ans += arr[x] > k;
			for (int x = j; x > max(s * sq, (e - 1) * sq); x--)	ans += arr[x] > k;
			for (int x = s + 1; x < e; x++)	ans += (bck[x].size() - (upper_bound(bck[x].begin(), bck[x].end(), k) - bck[x].begin()));
			cout << ans << '\n';
		}
		else {
			cin >> k;
			int from = arr[i], to = k;
			arr[i] = k;
			vector<int>::iterator iter = lower_bound(bck[s].begin(), bck[s].end(), from);
			bck[s].erase(iter);
			bck[s].push_back(to);
			sort(bck[s].begin(), bck[s].end());
		}
	}
	

}