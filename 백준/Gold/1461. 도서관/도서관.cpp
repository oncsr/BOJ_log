#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin>>N>>M;
    vector<int> posi, nega;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        if(a > 0)   posi.push_back(a);
        else    nega.push_back(-a);
    }
    sort(posi.begin(), posi.end());
    sort(nega.begin(), nega.end());
    int ans = 0, ps = posi.size(), ns = nega.size();
    for(int i=ps%M?ps%M-1:M-1;i<ps - M;i+=M)   ans += posi[i]*2;
    for(int i=ns%M?ns%M-1:M-1;i<ns - M;i+=M)   ans += nega[i]*2;
    if(posi.empty())    ans += nega.back();
    else if(nega.empty())   ans += posi.back();
    else    ans += posi.back() + nega.back() + min(posi.back(), nega.back());
    cout<<ans;
}