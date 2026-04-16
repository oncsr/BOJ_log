#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int arr[20]{};
	int a = 0, b = 0;
	for (int i = 0; i < 20; i++)	cin >> arr[i];
	for (int i = 0; i < 20; i++) {
		b += arr[i];
		if (arr[i] == 20) {
			a += (arr[(i + 19) % 20] + arr[i] + arr[(i + 1) % 20]);
		}
	}

	a *= 20, b *= 3;
	cout << (a > b ? "Alice" : (a == b ? "Tie" : "Bob"));

}