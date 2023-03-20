#include <iostream>
using namespace std;

int main() {
	
	int x;
	cin >> x;
	int g = 1, h = 1;
	while (g < x) {
		h++;
		g += h;
	}
	
	int t = g - x;
	if (h % 2)	cout << t + 1 << '/' << h - t;
	else	cout << h - t << '/' << t + 1;
}