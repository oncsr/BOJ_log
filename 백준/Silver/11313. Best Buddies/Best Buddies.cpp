#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin>>N;
    vector<pair<string, string>> A(N);
    for(auto &[b,a]:A)  cin>>a>>b;
    sort(A.begin(), A.end());
    map<pair<string, string>, int> M;
    int c=0;
    for(auto &[b,a]:A)  M[{a,b}]=c++;
    int Q;
    for(cin>>Q;Q--;){
        string a,b;
        cin>>a>>b;
        int id = M[{a,b}];
        set<pair<string,string>> S;
        for(int i=0;i<3;i++)    S.insert(A[id/3*3+i]);
        S.erase({b,a});
        for(auto &[x,y]:S)  cout<<y<<' '<<x<<'\n';
    }

}