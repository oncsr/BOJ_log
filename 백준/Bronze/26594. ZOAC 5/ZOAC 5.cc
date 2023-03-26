#include<iostream>
using namespace std;

int main() {
	string a;
	int n = 0, mn = 1000001;
	cin >> a;
	char temp = '0';
	for (char i : a) {
		if (temp == '0')	n++, temp = i;
		else {
			if (temp == i)	n++;
			else	break;
		}
	}
	cout << n;
}