#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	int arr[7]{}, s = 0;
	string a, b[7]{};
	b[0] = "Re", b[1] = "Pt", b[2] = "Cc", b[3] = "Ea";
	b[4] = "Tb", b[5] = "Cm", b[6] = "Ex";
	while (cin >> a) {
		s++;
		if (a == "Re")	arr[0]++;
		if (a == "Pt")	arr[1]++;
		if (a == "Cc")	arr[2]++;
		if (a == "Ea")	arr[3]++;
		if (a == "Tb")	arr[4]++;
		if (a == "Cm")	arr[5]++;
		if (a == "Ex")	arr[6]++;
	}
	for (int i = 0; i < 7; i++)
		cout << b[i] << ' ' << arr[i] << ' ' << (double)arr[i] / s << '\n';
	cout << "Total " << s << " 1.00";
	cout.unsetf(ios::fixed);
}