#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string arr[1000]{};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n, cmp);
	if (arr[0][0] == '0')	cout << 0;
	else {
		for (int i = 0; i < n; i++)	cout << arr[i];
	}
}