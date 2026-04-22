#include <iostream>
using namespace std;

int main() {
	string a;
	cin >> a;
	if (a[0] == 'N')	cout << "North London Collegiate School";
	else if (a[0] == 'B')	cout << "Branksome Hall Asia";
	else if (a[0] == 'K')	cout << "Korea International School";
	else	cout << "St. Johnsbury Academy";
}