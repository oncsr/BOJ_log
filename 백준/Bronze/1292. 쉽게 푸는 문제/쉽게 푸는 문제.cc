#include <iostream>
using namespace std;

int arr[1001];
int a, b;

int main() {
	cin >> a >> b;
	int index = 0;
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j <= i; j++) {
			arr[index] = i + 1;
			index++;
			if (index == 1001)
				break;
		}
	}
	int sum = 0;
	for (int i = a - 1; i < b; i++)
		sum += arr[i];
	cout << sum << '\n';
}