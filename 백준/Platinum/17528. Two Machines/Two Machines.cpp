#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

    int INF = 1e9;
    vector<int> A(62501, INF), B(62501, INF);
	int N;
	cin >> N;
    A[0] = 0, B[0] = 0;
    
	for (int a,b; N--;) {
		cin >> a >> b;
        vector<int> NA(62501, INF), NB(62501, INF);
		for(int i=0;i<=62500;i++){
            if(A[i] != INF) {
                NA[i+a] = min(NA[i+a], A[i]);
                NB[A[i]] = min(NB[A[i]], i+a);
            }
            if(B[i] != INF) {
                NB[i+b] = min(NB[i+b], B[i]); 
                NA[B[i]] = min(NA[B[i]], i+b);
            }
        }
        A = NA, B = NB;
	}
	int ans = 1234567890;
    for(int i=0;i<=62500;i++){
        if(A[i] != INF) ans = min(ans, max(i, A[i]));
        if(B[i] != INF) ans = min(ans, max(i, B[i]));
    }
	cout << ans;

}