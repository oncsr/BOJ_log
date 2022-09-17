#include <iostream>
using namespace std;

int max(int a[]) {
	int r1 = 0, r2 = 0, r3 = 0;
	for (int i = 0; i < 10; i++) {
		if (a[i] > r1)
			r1 = a[i];
	}
	for (int i = 0; i < 10; i++)
	{
		if (a[i] > r2)
		{
			if (a[i] == r1)
				continue;
			else
				r2 = a[i];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (a[i] > r3)
		{
			if (a[i] == r1)
				continue;
			else if (a[i] == r2)
				continue;
			else
				r3 = a[i];
		}
	}
	return r3;
}

int main() {
	int t;	cin >> t;
	while (t--) {
		int arr[10];
		for (int i = 0; i < 10; i++)
			cin >> arr[i];
		cout << max(arr) << '\n';
	}
}