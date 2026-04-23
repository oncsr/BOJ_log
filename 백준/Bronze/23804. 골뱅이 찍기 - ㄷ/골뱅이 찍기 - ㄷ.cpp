#include <iostream>
using namespace std;

int main() {
	int n;	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 5; j++)	cout << '@';
		cout << '\n';
	}
	for (int j = n; j < n * 4; j++) {
		for (int i = 0; i < n; i++)	cout << '@';
		cout << '\n';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 5; j++)	cout << '@';
		cout << '\n';
	}
}