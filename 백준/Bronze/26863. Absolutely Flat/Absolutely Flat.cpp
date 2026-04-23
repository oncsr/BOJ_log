#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if (a == b && b == c && c == d)	cout << 1;
	else {
		int arr[4] = { a,b,c,d };
		sort(arr, arr + 4);
		if (arr[1] == arr[2] && arr[2] == arr[3] && arr[0] + e == arr[1])	cout << 1;
		else	cout << 0;
	}
}