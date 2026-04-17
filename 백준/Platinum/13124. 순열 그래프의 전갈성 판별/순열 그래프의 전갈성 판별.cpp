#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin >> N;
	int arr[100001]{};
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	for (cin >> Q; Q--;) {
		int a, b;
		cin >> a >> b;
		swap(arr[a], arr[b]);
		bool cond1 = arr[1] == 3 && arr[2] == 1 && arr[N] == 2;
		bool cond2 = arr[1] == 2 && arr[2] == N && arr[3] == 1;
		bool cond3 = arr[1] == N - 1 && arr[N - 1] == N && arr[N] == N - 2;
		bool cond4 = arr[N - 2] == N && arr[N - 1] == 1 && arr[N] == N - 1;
		cout << (cond1 || cond2 || cond3 || cond4 ? "YES\n" : "NO\n");
	}
}