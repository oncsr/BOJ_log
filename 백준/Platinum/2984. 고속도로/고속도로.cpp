#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A[100001]{}, B[100000]{};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)    cin>>A[i]>>B[i];
    sort(A+1, A+n+1);
    sort(B+1, B+n+1);

    vector<ll> dp(100001, 1e18);
    dp[0] = 0;

    for(int i=1;i<=n;i++){
        int j = min(3, i);
        for(int k=1;k<=j;k++){
            vector<int> idx(k);
            for(int t=0;t<k;t++)    idx[t] = t;

            do{

                ll addv = 0, no = 0;
                for(int t=0;t<k;t++){
                    if(A[i-t] == B[i-idx[t]]){
                        no = 1;
                        break;
                    }
                    addv += abs(A[i-t] - B[i-idx[t]]);
                }

                if(!no) dp[i] = min(dp[i], dp[i-k] + addv);

            }while(next_permutation(idx.begin(), idx.end()));
            
        }
    }
    cout<<dp[n];

}