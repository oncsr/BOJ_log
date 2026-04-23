#include <iostream>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;	// first = position, second = weight



int main() {
	int N, L;
	cin >> N >> L;
	double w = 0, wx = 0, t;
	double x[100000]{};
	for (int i = 0; i < N; i++)	cin >> x[i];
	for (int i = 0; i < N; i++) {
		cin >> t;
		w += t;
		wx += t * x[i];
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << wx / w;
	cout.unsetf(ios::fixed);
}