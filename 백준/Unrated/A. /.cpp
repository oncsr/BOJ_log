#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i <= n - 4; i++)    if (s.substr(i, 4) == "gori")    return cout << "YES", 0;
    cout << "NO";
}