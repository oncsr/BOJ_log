#include <iostream>
#include <vector>
using namespace std;

int N, arr[20][20]{}, ans = 2147483647;

void solve(int n, vector<int> a, vector<int> b) {
	if (n == N) {
		if (a.size() != b.size())	return;
		int A = 0, B = 0;
		for (int i = 0; i < a.size(); i++)
			for (int j = 0; j < a.size(); j++)
				A += arr[a[i]][a[j]];
		for (int i = 0; i < b.size(); i++)
			for (int j = 0; j < b.size(); j++)
				B += arr[b[i]][b[j]];
		ans = min(ans, abs(A - B));
		return;
	}
	a.push_back(n);
	solve(n + 1, a, b);
	a.pop_back();
	b.push_back(n);
	solve(n + 1, a, b);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	solve(0, {}, {});
	cout << ans;
}