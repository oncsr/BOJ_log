#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<pair<int, int>>> V(200001);
vector<int> root(200001);

int find(int x){
    if(x==root[x])  return x;
    return root[x] = find(root[x]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    for(int i=1;i<N;i++){
        int a,b,c;
        cin>>a>>b>>c;
        V[c].push_back({a,b});
    }

    for(int i=1;i<=N;i++)   root[i] = i;

    ll arr[200001]{};
    ll brr[200001]{};
    ll coef[200001]{};
    for(int i=1;i<=N;i++)   cin>>arr[i];
    for(int i=1;i<=N;i++)   cin>>brr[i];

    for(int i=1;i<=200000;i++){
        if(V[i].empty())    continue;
        

        set<int> used;
        for(pair<int, int> e : V[i]){
            int a = e.first, b = e.second;
            int x = find(a), y = find(b);
            root[x] = y;
            used.insert(a), used.insert(b);
        }


        vector<pair<int, ll>> L;
        for(int i:used){
            L.push_back({find(i), i});
        }


        sort(L.begin(), L.end());
        int temp = L[0].first, last = 0;
        ll sum = 0;
        for(int i=0;i<L.size();i++){
            if(temp != L[i].first){
                for(int j=last;j<i;j++){
                    coef[L[j].second] += sum;
                    root[L[j].second] = L[j].second;
                }
                sum = 0;
                temp = L[i].first;
                last = i;
            }
            sum += arr[L[i].second];
        }
        for(int j=last;j<L.size();j++){
            coef[L[j].second] += sum;
            root[L[j].second] = L[j].second;
        }

    }
    sort(coef+1, coef+N+1, greater<>());
    sort(brr+1, brr+N+1, greater<>());
    ll ans1 = 0, ans2 = 0;
    for(int i=1;i<=N;i++){
        ans1 += coef[i] * brr[N+1-i];
        ans2 += coef[i] * brr[i];
    }
    cout<<ans1<<'\n'<<ans2;

}