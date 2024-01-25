#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;

using ii = pair<int, int>;
vector<int> remain(524289);
int info[200001]{};
int N;

map<int, ordered_set> M;

void init(int s, int e, int n){
    if(s==e){
        remain[n] = 1;
        return;
    }
    int m=(s+e)>>1;
    init(s,m,n*2);  init(m+1,e,n*2+1);
    remain[n] = remain[n*2]+remain[n*2+1];
}

void upt(int s, int e, int l, int r, int n){
    if(l > r || l > e || r < s) return;
    if(s == e){
        remain[n] = 0;
        int a = info[s];
        M[a].erase(s);
        return;
    }
    int m=(s+e)>>1;
    if(remain[n*2]) upt(s,m,l,r,n*2);
    if(remain[n*2+1])   upt(m+1,e,l,r,n*2+1);
    remain[n] = remain[n*2] + remain[n*2+1];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    
    cin>>N;
    for(int i=1;i<=N;i++){
        int a;
        cin>>a;
        info[i] = a;
        M[a].insert(i);
    }
    init(1,N,1);
    int Q;
    for(cin>>Q;Q--;){
        int a,b,c,d;
        cin>>a>>b>>c;
        if(a == 1){
            cin>>d;

            cout<<M[d].order_of_key(c+1) - M[d].order_of_key(b)<<'\n';
        }
        else{
            upt(1,N,b,c,1);
        }
    }

}