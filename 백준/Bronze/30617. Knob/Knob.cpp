#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    cin>>T;
    int l, r, L, R;
    cin>>l>>r;
    int score = 0;
    if(l == r && (l == 1 || l == -1))   score++;
    for(int i=1;i<T;i++){
        cin>>L>>R;
        if(L == l && (L == 1 || L == -1))   score++;
        if(R == r && (R == 1 || R == -1))   score++;
        if(L == R && (L == 1 || L == -1))  score++;
        l = L, r = R;
    }
    cout<<score;

}