#include <iostream>
#include <string>
using namespace std;

int main() {
	string c;
	cin >> c;
	int arr[9] = { 0 };
	int max = 0;
	for (int i = 0; i < c.size(); i++) {
		if (c[i] == '9')
			arr[6]++;
		else
			arr[c[i] - 48]++;
	}
	if (arr[6] % 2 == 0)
		arr[6] /= 2;
	else
		arr[6] = arr[6] / 2 + 1;
	for (int i = 0; i < 10; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	cout << max << '\n';
}