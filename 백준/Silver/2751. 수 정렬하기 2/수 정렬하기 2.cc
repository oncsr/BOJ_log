#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, mn = 1000001, mx = -1000001;
	cin >> N;
	int arr[2000001]{};
	for (int i = 0; i < N; i++) {
		cin >> a;
		mn = min(a, mn);
		mx = max(a, mx);
		arr[a + 1000000]++;
	}
	for (int i = mn + 1000000; i <= mx + 1000000; i++) {
		while (arr[i]) {
			cout << i - 1000000 << '\n';
			arr[i]--;
		}
	}
}