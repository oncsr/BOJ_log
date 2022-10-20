#include <iostream>
using namespace std;

int main() {
	int D, P, Q, mn = 1000000001;
	cin >> D >> P >> Q;
	if (P > Q)	swap(P, Q);

	if (D < P)	cout << P;
	else if (D % P == 0)	cout << D;
	else if (D % Q == 0)	cout << D;
	else if (D % (P + Q) == 0)	cout << D;
	else if (Q % P == 0)	cout << ((D / P) + 1) * P;
	else {
		int g = D / Q;
		g++;
		mn = Q * g;
		if (g > P)	g = P;
		int h = 0;
		while (g--) {
			mn = min(((D - Q * g - 1) / P + 1) * P + Q * g, mn);
			if (mn == D)	break;
		}
		mn = min(((D - 1) / P + 1) * P, mn);
		cout << mn;
	}

}