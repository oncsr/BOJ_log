#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[8]{};

void bck(int cur, vector<int> select) {
	if (select.size() == M) {
		for (int i : select) cout << i << ' ';
		cout << '\n';
		return;
	}

	if (select.size() > M) return;
	if (cur == N) return;

	// cur을 고른 경우
	select.push_back(arr[cur]);
	bck(cur + 1, select);
	// cur을 고르지 않은 경우
	select.pop_back();
	bck(cur + 1, select);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	bck(0, {});

}