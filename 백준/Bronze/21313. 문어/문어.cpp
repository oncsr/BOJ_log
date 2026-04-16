#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    if (n & 1) {
        for (int i = 0; i < n / 2; i++)  cout << "1 2 ";
        cout << 3;
    }
    else {
        for (int i = 0; i < n / 2; i++)  cout << "1 2 ";
    }

}