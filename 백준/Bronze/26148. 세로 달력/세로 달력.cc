#include <iostream>
using namespace std;

int main() {
	int N, a;
	cin >> N >> a;
	if (N % 400 == 0)	cout << 30;
	else {
		if (N % 4 == 0 && N % 100 != 0)	cout << 30;
		else	cout << 29;
	}
}