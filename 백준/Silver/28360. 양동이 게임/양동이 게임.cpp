#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> V(51);
double arr[51] = { 0,1000000000 };
int ch[51]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		ch[a]++;
	}

	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0)	continue;
		bool ex = 1;
		for (int j : V[i]) {
			ex = 0;
			arr[j] += arr[i] / ch[i];
		}
		if (!ex)	arr[i] = 0;
	}

	double mx = 0;
	for (int i = 1; i <= N; i++)	mx = max(mx, arr[i]);

	cout.precision(9);
	cout << fixed << mx / 10000000;
}