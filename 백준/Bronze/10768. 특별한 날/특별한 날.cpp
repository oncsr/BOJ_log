#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int a, b;
	cin >> a >> b;
	if (100 * a + b == 218)	cout << "Special";
	else if (100 * a + b < 218)	cout << "Before";
	else	cout << "After";
	
}