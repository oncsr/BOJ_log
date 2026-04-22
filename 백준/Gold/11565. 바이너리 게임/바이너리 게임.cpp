#include <iostream>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int aa = 0, bb = 0;
	for (char i : a)	aa += (i == '1');
	for (char i : b)	bb += (i == '1');
	if ((aa % 2 == 1 && aa + 1 >= bb) || (aa % 2 == 0 && aa >= bb))	cout << "VICTORY";
	else	cout << "DEFEAT";
}