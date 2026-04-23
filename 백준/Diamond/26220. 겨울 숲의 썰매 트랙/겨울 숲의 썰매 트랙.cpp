#include <iostream>
using namespace std;

int main() {
	int n;
	string a = "";
	cin >> n;
	if (n == 3)	cout << "4\n2 1\nRULD";
	else {
		for (int i = 0; i < n / 2 - 1; i++)	a += "RURD";
		a += "RDRDLD";
		if (n % 4 == 1) {
			for (int i = 0; i < n / 4 - 1; i++) {
				for (int i = 0; i < n / 2 - 2; i++)	a += "LULD";
				a += "LDRD";
				for (int i = 0; i < n / 2 - 2; i++)	a += "RURD";
				a += "RDLD";
			}
			for (int i = 0; i < n / 2 - 2; i++)	a += "LULD";
			a += "LULU";
			for (int i = 0; i < n / 2 - 2; i++)	a += "LURU";
			a += "LU";
		}
		else {
			for (int i = 0; i < n / 2 - 2; i++)	a += "RDLD";
			a += "LU";
			for (int i = 0; i < n / 4 - 1; i++) {
				for (int j = 0; j < n / 2 - 2; j++)	a += "LURU";
				a += "LULD";
				for (int j = 0; j < n / 2 - 2; j++)	a += "LDRD";
				a += "LDLU";
			}
			a += "LDLULULURU";
			for (int i = 0; i < n / 4 - 1; i++)	a += "RDRURULULDLULURU";
			a += "LU";
		}
		cout << a.size() << "\n2 1\n" << a;
	}
}