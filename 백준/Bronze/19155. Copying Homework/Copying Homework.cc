#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, arr[100000]{};
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	for (int i = 1; i < n + 1; i++)	cout << arr[i % n] << ' ';
}