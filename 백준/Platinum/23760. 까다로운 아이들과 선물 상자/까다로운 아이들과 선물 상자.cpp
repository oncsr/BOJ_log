#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

void remove(ordered_set *s, int v) { s->erase(s->find_by_order(s->order_of_key(v))); }

int N, M, w[100000]{};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ordered_set s;
    cin>>N>>M;
    for(int i=0,a;i<N;i++) {
        cin>>a;
        s.insert(a);
    }

    for(int i=0;i<M;i++) cin>>w[i];
    for(int i=0,b;i<M;i++) {
        cin>>b;
        int v = *s.find_by_order(b-1);
        if(w[i] > v) return cout<<0,0;
        remove(&s, v);
        s.insert(v-w[i]);
    }
    cout<<1;

}