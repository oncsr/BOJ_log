#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, p, c = 1;
    cin >> a >> p;
    map<ll, int> M;
    do {
        M[a] = c++;
        string temp = to_string(a);
        a = 0;

        for (char i : temp) {
            ll k = i - '0', s = 1;
            for (int j = 0; j < p; j++)    s *= k;
            a += s;
        }

    } while (!M[a]);
    cout << M[a] - 1;
}