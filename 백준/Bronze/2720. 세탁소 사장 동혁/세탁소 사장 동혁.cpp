#include <iostream>
using namespace std;
#define print(a,b)	cout<<(a)/(b)<<' ';	(a) -= (a)/(b)*(b)

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T, C, a[4] = { 25,10,5,1 };
	for (cin >> T; T--;) {
		cin >> C;
		for (int i = 0; i < 4; i++) {
			print(C, a[i]);
		}
		cout << '\n';
	}
}