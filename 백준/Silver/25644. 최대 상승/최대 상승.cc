#include <iostream>
using namespace std;

int main() {
	int n, s = 0, temp;
	cin >> n;
	int arr[200000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (!i)	temp = arr[i];
		if (arr[i] < temp)	temp = arr[i];
		if (arr[i] - temp > s) {
			s = arr[i] - temp;
		}
	}
	cout << s;
}