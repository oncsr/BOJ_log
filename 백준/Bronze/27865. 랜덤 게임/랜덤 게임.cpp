#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, limit = 20000;
	char o;
	cin >> N;
	while (limit--) {
		cout << "? " << 1 << endl;
		cin >> o;
		if (o == 'Y') {
			cout << "! " << 1 << endl;
			break;
		}
	}
}