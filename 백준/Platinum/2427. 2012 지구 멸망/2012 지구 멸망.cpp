#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
	ll N, P, V;
	cin >> N >> P >> V;
	if (N == 1) {
		cout << 0;
		return 0;
	}

	ll mn2 = N * P + V;
	for (ll i = 2; i <= log2(N); i++) {
		ll fac = pow(N, 1.0 / i);
		ll inc = 0;	// n보다 크게 하는 fac + 1의 최소 개수
		ll S = 1;
		for (int g = 0; g < i; g++)	S *= fac;
		while (inc < i && S < N) {
			inc++;
			S *= (fac + 1);
			S /= fac;
		}
		//while (pow(fac + 1, inc) * pow(fac, i - inc) < N)	inc++;
		mn2 = min(mn2, (i * fac + inc) * P + i * V);
	}
	cout << mn2 << '\n';
}