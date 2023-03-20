#include <iostream>
using namespace std;

int main() {
	int N, s, e;
	cin >> N;
	cout << "? 1" << endl;
	cin >> s;
	cout << "? " << N << endl;
	cin >> e;
	cout << "! ";
	if (s == e)	cout << 0;
	else if (s > e)	cout << -1;
	else	cout << 1;
	cout << endl;
}