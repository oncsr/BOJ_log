#include <iostream>
using namespace std;

int main() {
	double total = 0, score = 0;
	for (int i = 20; i--;) {
		string a;
		cin >> a;
		double b;
		cin >> b;
		char c;
		cin >> c;
		if (c == 'F')	total += b;
		else if (c == 'P')	continue;
		else {
			char d;
			cin >> d;
			double temp = 0;
			if (c == 'A')	temp += 4;
			if (c == 'B')	temp += 3;
			if (c == 'C')	temp += 2;
			if (c == 'D')	temp += 1;
			if (d == '+')	temp += 0.5;
			score += temp * b;
			total += b;
		}
	}
	cout.setf(ios::fixed);
	cout.precision(6);
	if (total == 0.)	cout << "0.000000";
	else	cout << score / total;
	cout.unsetf(ios::fixed);
}