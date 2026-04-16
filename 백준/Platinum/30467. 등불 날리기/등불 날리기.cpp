#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int N, S;
queue<int> q;
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>S;
    ll ans = 0, res = 0;
    for(int i=0,a;i<N;i++) {
        cin>>a;
        q.push(a);
        if(q.size() > S) {
            int b = q.front(); q.pop();
            res -= S - s.order_of_key(b+1);
            s.erase(s.find_by_order(s.order_of_key(b)));
        }
        s.insert(a);
        res += s.order_of_key(a);
        if(q.size() == S) ans = max(ans, res);
    }
    cout<<ans;

}