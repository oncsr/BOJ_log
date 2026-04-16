#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int t;
    for(cin>>t;t--;){

    int INF = 1e9;
    vector<int> A(100001, INF), B(100001, INF);
	int N;
	cin >> N;
    A[0] = 0, B[0] = 0;
    
	for (int a,b; N--;) {
		cin >> a >> b;
        vector<int> NA(100001, INF), NB(100001, INF);
		for(int i=0;i<=100000;i++){
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
    for(int i=0;i<=100000;i++){
        if(A[i] != INF) ans = min(ans, max(i, A[i]));
        if(B[i] != INF) ans = min(ans, max(i, B[i]));
    }
	cout << ans<<'\n';
    }

}