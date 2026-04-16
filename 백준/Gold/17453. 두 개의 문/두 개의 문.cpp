#include <bits/stdc++.h>
using namespace std;

int N, M;

bitset<100> operator+(bitset<100> a, bitset<100> b) {
	for (int i = 0; i < N; i++) {
		if (b[i])	a[i].flip();
	}
	return a;
}

bitset<100> base;
bitset<100> arr[20]{};

vector<int> ans(201, -1);
void sol(int pos, bitset<100> state, int chosen) {
	if (pos == M) {
		int cnt = N;
		for (int i = 0; i < N; i++)	cnt += (state[i] ? 1 : -1);
		ans[cnt] = chosen;
		return;
	}
	sol(pos + 1, state, chosen);
	state = state + arr[pos];
	sol(pos + 1, state, chosen | (1 << pos));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;
	string a;
	cin >> a;
	for (int i = 0; i < N; i++)	base[i] = a[i] == '1';

	for (int i = 0; i < M; i++) {
		cin >> a;
		for (int j = 0; j < N; j++)	arr[i][j] = a[j] == '1';
	}

	sol(0, base, 0);

	for (int i = 0; i <= 2 * N; i++) {
		if (ans[i] == -1) { cout << "-1\n"; continue; }
		vector<int> temp;
		for (int j = 0; j < M; j++) {
			if (ans[i] & (1 << j))	temp.push_back(j);
		}
		cout << temp.size() << ' ';
		for (int j : temp)	cout << j + 1 << ' ';
		cout << '\n';
	}

}