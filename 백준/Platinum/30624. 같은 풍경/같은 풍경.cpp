#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
#define x first
#define y second

ll N, M, X, Y;

ll ccw(pl a, pl b, pl c) {
	ii vec1 = { b.x - a.x,b.y - a.y };
	ii vec2 = { c.x - b.x,c.y - b.y };

	return (ll)vec1.x * vec2.y - (ll)vec1.y * vec2.x;
}

bool cmp(pl a, pl b){ return ccw({X,Y}, a, b) > 0; }

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M>>X>>Y;
    vector<pl> arr(N);

    for(int i=0;i<N;i++){
        cin>>arr[i].x>>arr[i].y;
    }

    sort(arr.begin(), arr.end(), cmp);

    priority_queue<ll> up;
    priority_queue<ll, vector<ll>, greater<>> low;

    for(int i=0;i<N-1;i++){
        ll px  = arr[i].x, py = arr[i].y;
        ll qx = arr[i+1].x, qy = arr[i+1].y;
        if(py == qy)    continue;
        ll GU = py*(px-qx), GD = py-qy;
        ll xx = px - py*(px-qx)/(py-qy);
        if(arr[i].y < arr[i+1].y){
            // low
            if(GU % GD == 0)    low.push(xx-1);
            else    low.push(xx);
        }
        else{
            if(GU % GD == 0)    up.push(xx+1);
            else    up.push(xx);
        }

    }

    ll L = (up.empty() ? -1000000001 : up.top());
    ll R = (low.empty() ? 1000000001 : low.top());

    int ans = 0;

    for(int i=0;i<M;i++){
        int a;
        cin>>a;
        if(L <= a && a <= R)    ans++;
    }
    cout<<ans;

}