#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> cranes, boxes, capacity;

void input(int &n, vector<int> &arr) {
	cin >> n;
	arr.resize(n);
	for (int& i : arr) cin >> i;
	sort(arr.begin(), arr.end());
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	input(N, cranes);
	input(M, boxes);
	if (cranes.back() < boxes.back()) {
		return cout << -1, 0;
	}

	capacity.resize(N);
	int pos = 0;
	for (int i = 0; i < N; i++) {
		while (pos < M && cranes[i] >= boxes[pos]) {
			capacity[i]++;
			pos++;
		}
	}

	int s = 1, e = 1000001, m = (s + e) >> 1;
	while (s < e) {
		int rem = 0;
		for (int cap : capacity) {
			if (cap + rem > m) {
				rem = cap + rem - m;
			}
			else {
				rem = 0;
			}
		}
		if (rem) s = m + 1;
		else e = m;
		m = (s + e) >> 1;
	}
	cout << m;
	
}