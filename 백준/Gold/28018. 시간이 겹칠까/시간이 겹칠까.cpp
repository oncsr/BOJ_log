#include <iostream>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	int arr1[100000]{}, arr2[100000]{};
	for (int i = 0; i < N; i++)	cin >> arr1[i] >> arr2[i];
	sort(arr1, arr1 + N);
	sort(arr2, arr2 + N);
	int Q;
	for (cin >> Q; Q--;) {
		int a;
		cin >> a;
		int c1 = upper_bound(arr1, arr1 + N, a) - arr1;
		int c2 = lower_bound(arr2, arr2 + N, a) - arr2;
		cout << c1 - c2 << '\n';
	}
}