#include <iostream>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
typedef long long ll;

int main() {
	ll c, d;
	cin >> c >> d;
	ll a = min(c, d);
	ll b = max(c, d);
	ll x, y;
	cin >> x >> y;
	ll q = (a - y) / x;
	if (x < 0) {
		if (y >= -1 * x || y < 0)
			cout << "Unknwon Number\n";
		else {
			if (q * x + y < a) {
				while (q * x + y < a)
					q--;
				if (q * x + y >= a && q * x + y <= b) {
					if ((q - 1) * x + y >= a && (q - 1) * x + y <= b)
						cout << "Unknwon Number\n";
					else
						cout << q * x + y << '\n';
				}
				else
					cout << "Unknwon Number\n";
			}
			else {
				if (q * x + y >= a && q * x + y <= b) {
					if ((q - 1) * x + y >= a && (q - 1) * x + y <= b)
						cout << "Unknwon Number\n";
					else
						cout << q * x + y << '\n';
				}
				else
					cout << "Unknwon Number\n";
			}
		}
	}
	else if (x > 0) {
		if (y >= x || y < 0)
			cout << "Unknwon Number\n";
		else {
			if (q * x + y < a) {
				while (q * x + y < a)
					q++;
				if (q * x + y >= a && q * x + y <= b) {
					if ((q + 1) * x + y >= a && (q + 1) * x + y <= b)
						cout << "Unknwon Number\n";
					else
						cout << q * x + y << '\n';
				}
				else
					cout << "Unknwon Number\n";
			}
			else {
				if (q * x + y >= a && q * x + y <= b) {
					if ((q + 1) * x + y >= a && (q + 1) * x + y <= b)
						cout << "Unknwon Number\n";
					else
						cout << q * x + y << '\n';
				}
				else
					cout << "Unknwon Number\n";
			}
		}
	}
	else
		cout << "Unknwon Number\n";
}