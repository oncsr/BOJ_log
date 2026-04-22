#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int one = 0, two = 0;
	int arr[100000]{};
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		int a = arr[i];
		if (two) {
			int g = a / 2;
			a -= min(g, two) * 2;
			two -= min(g, two);
			
		}
		if (one) {
			int g = a;
			a -= min(g, one);
			one -= min(g, one);
		}
		a %= 3;
		if (a == 1)	two++;
		else if (a == 2)	one++;
	}
	if (one || two)	cout << "NO";
	else	cout << "YES";
}