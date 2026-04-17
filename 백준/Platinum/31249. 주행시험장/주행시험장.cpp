#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    for (cin >> T; T--;) {
        ll n, m;
        cin >> n >> m;
        if (n > m) swap(n, m);
        ll k = n;
        if (m > 2 * n) k++;
        ll cnt;
        if (n == m)  cnt = 3;
        else {
            if (k == 1) cnt = (n + m) * 2 + 1;
            else {
                if (m + n <= 2 * k) cnt = 5;
                else {
                    cnt = 7;
                    cnt += 2 * max(0LL, m - 2 * k);
                }
            }
        }
        cout << k << ' ' << cnt << '\n';
    }

}