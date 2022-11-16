#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visit[8]{};
int N, M;
int arr[8]{};

void R(int n, vector<int> ans) {
	for (int i = 0; i < N; i++) {
		ans.push_back(arr[i]);
		if (n < M)	R(n + 1, ans);
		else {
			for (int i : ans)	cout << i << ' ';
			cout << '\n';
		}
		ans.pop_back();
	}
}

int main() {
	cin >> N >> M;
	vector<int> a;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);
	R(1, a);
}