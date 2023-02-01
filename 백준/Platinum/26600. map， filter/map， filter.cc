#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    vector<ll> before_mod;
    vector<ll> after_mod(100);
    ll multi = 1, add = 0;
    bool mod = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll g;
        cin >> g;
        before_mod.push_back(g);
    }
    sort(before_mod.begin(), before_mod.end());
    for (cin >> q; q--;) {
        string op;
        ll a;
        cin >> op;
        if (op == "map") {
            char o;
            cin >> o >> a;
            if (o == '+')    add += a;
            if (o == '*')    multi *= a, add *= a;
            if (o == '%') {
                if (!mod) {
                    for (int i = 0; i < n; i++) {
                        ll val = (before_mod[i] * multi + add) % a;
                        after_mod[val]++;
                    }
                    mod = true;
                }
                else {
                    vector<ll> temp(100);
                    for (ll i = 0; i < 100; i++) {
                        if (after_mod[i]) {
                            ll val = (i * multi + add) % a;
                            temp[val] += after_mod[i];
                        }
                    }
                    after_mod = temp;
                }
                multi = 1, add = 0;
            }
        }
        else {
            string o;
            cin >> o >> a;
            if (!mod) {
                double check_val = ((double)a - add) / multi;
                if (check_val >= 0) {
                    if (o == ">=") {
                        check_val = (ll)ceil(check_val);
                        cout << n - (lower_bound(before_mod.begin(), before_mod.end(), check_val) - before_mod.begin()) << '\n';
                    }
                    if (o == "<=") {
                        cout << upper_bound(before_mod.begin(), before_mod.end(), (ll)check_val) - before_mod.begin() << '\n';
                    }
                    if (o == "==") {
                        if ((a - add) % multi)
                            cout << "0\n";
                        else
                            cout << upper_bound(before_mod.begin(), before_mod.end(), (ll)check_val) - lower_bound(before_mod.begin(), before_mod.end(), (ll)check_val) << '\n';
                    }
                }
                else    cout << "0\n";
            }
            else {
                ll cnt = 0;
                for (ll i = 0; i < 100; i++) {
                    if (after_mod[i]) {
                        ll val = i * multi + add;
                        if (o == ">=" && val >= a)   cnt += after_mod[i];
                        if (o == "<=" && val <= a)   cnt += after_mod[i];
                        if (o == "==" && val == a)   cnt += after_mod[i];
                    }
                }
                cout << cnt << '\n';
            }
        }
    }
}