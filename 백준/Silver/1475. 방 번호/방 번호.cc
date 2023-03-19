#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;
	int arr[10]{};
	for (char i : s) {
		if (i == '6' || i == '9') {
			if (arr[6] > arr[9])	arr[9]++;
			else	arr[6]++;
		}
		else	arr[i - '0']++;
	}
	int mx = 0;
	for (int i = 0; i < 10; i++)	mx = max(mx, arr[i]);
	cout << mx;
}