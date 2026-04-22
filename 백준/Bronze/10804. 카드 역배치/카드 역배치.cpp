#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> V(21);
	for (int i = 1; i <= 20; i++)	V[i] = i;
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		reverse(V.begin() + a, V.begin() + 1 + b);
	}
	for (int i = 1; i <= 20; i++)	cout << V[i] << ' ';
}