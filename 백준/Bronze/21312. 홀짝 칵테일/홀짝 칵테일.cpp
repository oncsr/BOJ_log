#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;
    int res = 1, res2 = 1;
    int odd = 0;
    if (a & 1) res *= a, odd++;
    else    res2 *= a;
    if (b & 1) res *= b, odd++;
    else    res2 *= b;
    if (c & 1) res *= c, odd++;
    else    res2 *= c;
    if (!odd)    return cout << res2, 0;
    cout << res;

}