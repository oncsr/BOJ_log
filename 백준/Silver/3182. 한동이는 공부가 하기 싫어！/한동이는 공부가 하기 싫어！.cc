#include <iostream>
using namespace std;

int main() {
	int n, arr[1001]{}, cnt[1001]{}, mx = 0, id = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		cnt[i] = 1;
		int t = arr[i];
		int visit[1001]{};
		visit[i]++;
		while (!visit[t]) {
			cnt[i]++;
			visit[t]++;
			t = arr[t];
		}
		if (cnt[i] > mx) {
			mx = cnt[i];
			id = i;
		}
	}
	cout << id;
}