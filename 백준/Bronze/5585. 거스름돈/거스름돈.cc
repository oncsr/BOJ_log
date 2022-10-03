#include <iostream>
using namespace std;

int main() {
	int n, s = 0;
	cin >> n;
	n = 1000 - n;
	s += (n / 500);
	n %= 500;
	s += (n / 100);
	n %= 100;
	s += (n / 50);
	n %= 50;
	s += (n / 10);
	n %= 10;
	s += (n / 5);
	n %= 5;
	s += n;
	cout << s;
}