#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string A;
ll ans = 0;
void sol(int pos, string a, string b){
    if(pos == A.size()){
        if(a == "" || b == "")  return;
        ans = max(ans, stoll(a)*stoll(b));
        return;
    }
    sol(pos+1, a+A[pos], b);
    sol(pos+1, a, b+A[pos]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    for(cin>>T;T--;){
        cin>>A;
        for(char &i:A)  if(i == '6')i='9';
        sort(A.begin(), A.end(), greater<>());
        ans = 0;
        sol(0,"","");
        cout<<ans<<'\n';
    }

}