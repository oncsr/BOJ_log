#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, m;
    cin>>N>>m;

    vector<int> P(1001, -1), M(1001, -1);
    for(int i=0;i<m;i++){
        int a,c;
        char b;
        cin>>a>>b>>c;
        if(b == 'P')    P[a] = c;
        else    M[a] = c;
    }

    int plant = 0, no = 0;

    for(int i=1;i<=N;i++){
        if(P[i] == 1 && M[i] == 0)  plant++;
        else if(P[i] == 0 || M[i] == 1) no++;
    }

    cout<<plant<<' '<<N-no;

}