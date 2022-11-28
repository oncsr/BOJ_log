#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n > m)	swap(n, m);
	if (n == 1 && m == 2)	cout << "ChongChong";
	else	cout << "GomGom";
}