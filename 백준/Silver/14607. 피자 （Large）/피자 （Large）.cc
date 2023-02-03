#include <iostream>
using namespace std;
using ll = long long;

ll dp(ll a) {
    if (a == 1)return 0;
    if (a % 2) {
        ll n = a / 2, b = a / 2 + 1;
        return dp(n) + dp(b) + n * b;
    }
    else return 2 * dp(a / 2) + (a / 2) * (a / 2);
}

int main() {
    ll n; cin >> n;
    cout << dp(n);
}