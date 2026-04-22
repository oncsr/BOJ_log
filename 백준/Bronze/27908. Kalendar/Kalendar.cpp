#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr) {
	cout << '|';
	for (int i = 0; i < 7; i++) {
		if (!arr[i])	cout << "...";
		else {
			if (arr[i] < 10)	cout << ".." << arr[i];
			else	cout << '.' << arr[i];
		}
	}
	cout << "|\n";
}

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> arr(7);
	cout << "+---------------------+\n";
	int pos = 0, num = 1;
	for (; pos < 7 && pos < d - 1; pos++)	arr[pos] = 0;
	for (; pos < 7 && num <= n; pos++, num++)	arr[pos] = num;
	print(arr);

	while (num <= n) {
		arr = vector<int>(7);
		pos = 0;
		for (; pos < 7 && num <= n; pos++, num++)	arr[pos] = num;
		print(arr);
	}

	cout << "+---------------------+\n";

}