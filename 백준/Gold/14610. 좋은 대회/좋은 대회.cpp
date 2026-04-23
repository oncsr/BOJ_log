#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	bool suc = true;
	cin >> N >> M;
	bool arr[11]{};
	int arr2[100][11]{};
	int possible[100]{};
	for (int i = 0; i < N; i++) {
		cin >> possible[i];
		if (possible[i] == M)	suc = false;
		if (possible[i] == 0)	suc = false;
		for (int j = 1; j <= M; j++) {
			cin >> arr2[i][j];
			if (arr2[i][j] == 1)	arr[j] = 1, possible[i]--;
		}
	}
	for (int j = 1; j <= M; j++) {
		if (arr[j])	continue;

		bool yes = false;
		for (int i = N - 1; i >= 0; i--) {
			// already know or can't solve
			if (arr2[i][j] != -1)	continue;
			if (!possible[i])	continue;

			possible[i]--;
			arr2[i][j] = 1;
			arr[j] = 1;
			yes = true;
			break;
		}
		if (!yes)	suc = false;
	}
	cout << (suc ? "YES" : "NO");
}