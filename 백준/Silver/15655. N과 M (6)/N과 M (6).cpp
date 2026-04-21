#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[8]{};

void Backtracking(int now, vector<int> select) {

	if (now == N) {
		if (select.size() == M) {
			for (int i : select)	cout << i << ' ';
			cout << '\n';
		}
		return;
	}

	select.push_back(arr[now]);
	Backtracking(now + 1, select);

	select.pop_back();
	Backtracking(now + 1, select);

}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> arr[i];

	sort(arr, arr + N);

	Backtracking(0, {});

}