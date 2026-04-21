#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T, t = 1;
    for(cin>>T;t<=T;t++){
        int n, ans = 1;
        cin>>n;
        
        for(int i=2;i*i<=n;i++){
            int cnt = 0;
            while(n % i == 0){
                n /= i;
                cnt++;
            }
            ans *= (2*cnt+1);
        }
        if(n > 1)   ans *= 3;
        
        cout<<"Scenario #"<<t<<":\n";
        cout<<ans/2+1<<"\n\n";

    }
}