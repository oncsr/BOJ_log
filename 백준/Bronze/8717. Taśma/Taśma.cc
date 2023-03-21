#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	int arr[1000001]{};
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	int mn = 2000000001;
	for (int i = 1; i < N; i++)
		mn = min(mn, abs(arr[i] - (arr[N] - arr[i])));
	cout << mn;
}