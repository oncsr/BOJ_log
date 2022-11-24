#include <iostream>
using namespace std;

int arr[7]{}, s = 0;

void print(int idx) {
	if (idx == 0)	cout << "Re ";
	if (idx == 1)	cout << "Pt ";
	if (idx == 2)	cout << "Cc ";
	if (idx == 3)	cout << "Ea ";
	if (idx == 4)	cout << "Tb ";
	if (idx == 5)	cout << "Cm ";
	if (idx == 6)	cout << "Ex ";
	cout << arr[idx] << ' ';
	cout << (double)arr[idx] / s << '\n';
}

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	string a;
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
	for (int i = 0; i < 7; i++)	print(i);
	cout << "Total " << s << " 1.00";
	cout.unsetf(ios::fixed);
}