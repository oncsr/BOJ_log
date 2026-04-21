#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    string name;
    ll salary;
};

node seg[524289]{};
node arr[200001]{};
int N, A;

node mrg(node a, node b){
    if(a.salary == b.salary)    return a.name < b.name ? a : b;
    return a.salary > b.salary ? a : b;
}

void init(int s, int e, int n){
    if(s==e){
        seg[n] = arr[s];
        return;
    }
    int m=(s+e)>>1;
    init(s,m,n*2);  init(m+1,e,n*2+1);
    seg[n] = mrg(seg[n*2], seg[n*2+1]);
}

void change(int s, int e, int i, ll v, int n){
    if(s==e){
        seg[n].salary += v;
        return;
    }
    int m=(s+e)>>1;
    if(i <= m)  change(s,m,i,v,n*2);
    else    change(m+1,e,i,v,n*2+1);
    seg[n] = mrg(seg[n*2], seg[n*2+1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>A;
    map<string, int> M;
    for(int i=1;i<=N;i++){
        cin>>arr[i].name>>arr[i].salary;
        M[arr[i].name] = i;
    }
    init(1,N,1);
    for(;A--;){
        int o;
        cin>>o;
        if(o == 1){
            string s;
            ll a;
            cin>>s>>a;
            change(1,N,M[s],a,1);
        }
        else{
            node ans = seg[1];
            cout<<ans.name<<' '<<ans.salary<<'\n';
            change(1,N,M[ans.name],-ans.salary,1);
        }
    }

}