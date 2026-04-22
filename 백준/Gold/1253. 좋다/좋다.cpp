#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[2000]{}, vis[2000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);

	int s = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int ch = arr[i] + arr[j];
			int upp = upper_bound(arr, arr + N, ch) - arr;
			int low = lower_bound(arr, arr + N, ch) - arr;
			if (upp == low)	continue;
			if (vis[low])	continue;
			if (low == N || low == i || low == j)	continue;
			int temp = arr[low];
			for (int k = low; k < upp; k++)	vis[k]++, s++;
		}
	}
	cout << s;
}