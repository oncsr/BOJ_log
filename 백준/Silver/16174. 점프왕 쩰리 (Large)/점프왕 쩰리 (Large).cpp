#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int arr[65][65]{}, poss[65][65]{};
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= N; j++)	cin >> arr[i][j];
	poss[1][1] = 1;
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= N; j++) {
		if (!poss[i][j])	continue;
		int x = i + arr[i][j], y = j + arr[i][j];
		if (x <= N)	poss[x][j] = 1;
		if (y <= N)	poss[i][y] = 1;
	}
	cout << (poss[N][N] ? "HaruHaru" : "Hing");

}