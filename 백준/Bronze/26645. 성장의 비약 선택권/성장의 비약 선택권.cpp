#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n > 228)	cout << 4;
	else if (n > 217)	cout << 3;
	else if (n > 205)	cout << 2;
	else	cout << 1;
}