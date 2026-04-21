#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    for(cin>>t;t--;){
        int n;
        cin>>n;
        vector<ld> arr(n);
        for(auto &i : arr)    cin>>i;
        vector<int> ord(n);
        for(int i=0;i<n;i++)    ord[i] = i;

        ld ans = 1e18;

        do{
            vector<ld> bot(n);
            for(int i=1;i<n;i++){
                ld ri = arr[ord[i]];
                for(int j=i-1;j>=0;j--){
                    ld rj = arr[ord[j]];

                    ld C = ri+rj, B = abs(ri-rj);
                    ld F = sqrt(C*C-B*B);
                    bot[i] = max(bot[i], bot[j] + F);

                }
            }
            ld D = 0;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    D = max(D, arr[ord[i]] + bot[j]-bot[i] + arr[ord[j]]);
                }
            }

            ans = min(ans, D);

        }while(next_permutation(ord.begin(), ord.end()));
        
        cout.setf(ios::fixed);
        cout.precision(3);
        cout<<ans<<'\n';
        cout.unsetf(ios::fixed);

    }

}