#include <iostream>
#include <stack>
using namespace std;

int N;
stack<pair<int, int>> s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int t; cin >> t;
        while (!s.empty() && s.top().first < t) {
            s.pop();
        }
        if (s.empty()) {
            cout << 0 << ' ';
        }
        else {
            cout << s.top().second << ' ';
        }

        s.push({ t, i });
    }

    return 0;
}