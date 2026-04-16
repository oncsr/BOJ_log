#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int& i : A)	cin >> i;
    sort(A.begin(), A.end());

    vector<int> B = { A[0] };
    for (int i = 1; i < N; i++)	B.push_back(A[i] - A[i - 1]);
    sort(B.begin(), B.end());

    int ans = 0;
    for (int i = 0; i < N - K; i++)	ans += B[i];
    cout << ans;

}