#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ll;



int main() {
	int L;
	cin >> L;
	string a;
	cin >> a;
	ll sum = 0;
	for (int i = 0; i < a.size(); i++) {
        ll k = 1;
        for (int j=0;j<i;j++)
            k *= 31, k%=1234567891;
		sum += ((a[i] - 96) * k)%1234567891;
    }
	cout << sum%1234567891 << '\n';
}