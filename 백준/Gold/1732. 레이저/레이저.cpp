#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
#define x first
#define y second

bool cmp(ii a, ii b){
    if(abs(a.first) == abs(b.first))    return a.second > b.second;
    return abs(a.first) < abs(b.first);
}

int gcd(int a, int b){
    if(a < b)   swap(a,b);
    return a%b?gcd(b,a%b):b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    map<ii, vector<ii>> M;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a == 0){
            M[{0,1}].emplace_back(b,c);
            continue;
        }
        ii pr;
        if(b == 0) pr = {a>0?1:-1,0};
        else{
            int g = gcd(abs(a), b);
            pr = {a/g, b/g};
        }
        M[pr].emplace_back(a,c);
    }

    vector<ii> ans;
    for(auto it = M.begin();it != M.end();it++){
        vector<ii> &V = (*it).second;
        int dx = (*it).first.first;
        int dy = (*it).first.second;

        sort(V.begin(), V.end(), cmp);
        int temp = -1;
        for(ii P : V){
            if(P.second <= temp){
                ans.emplace_back(P.first, dy * P.first / dx);
            }
            else    temp = P.second;
        }

    }

    sort(ans.begin(), ans.end());
    for(ii i:ans)   cout<<i.first<<' '<<i.second<<'\n';

}