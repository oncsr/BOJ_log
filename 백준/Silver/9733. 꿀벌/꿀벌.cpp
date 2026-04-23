#include <iostream>
#include <map>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	map<string, int> M;
	string a, b[7] = { "Re","Pt","Cc","Ea","Tb","Cm","Ex" };
	int s = 0;
	while (cin >> a) {
		M[a]++;
		s++;
	}
	for (int i = 0; i < 7; i++)
		cout << b[i] << ' ' << M[b[i]] << ' ' << (double)M[b[i]] / s << '\n';
	cout << "Total " << s << " 1.00";
	cout.unsetf(ios::fixed);
}