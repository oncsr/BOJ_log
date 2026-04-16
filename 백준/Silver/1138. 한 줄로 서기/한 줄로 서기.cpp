#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, arr[11]{};
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	vector<int> ord(N);
	iota(ord.begin(), ord.end(), 1);
	do {

		int temp[11]{};
		for (int i = 0; i < N; i++) {
			int h = ord[i], c = 0;
			for (int j = 0; j < i; j++)	c += (ord[j] > h);
			temp[h] = c;
		}

		int same = 0;
		for (int i = 1; i <= N; i++)	same += (temp[i] == arr[i]);
		if (same == N) {
			for (int i : ord)	cout << i << ' ';
			return 0;
		}

	} while (next_permutation(ord.begin(), ord.end()));

}