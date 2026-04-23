#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (30 % (i + 1) == 0)	cout << i << '\n';
	}
}