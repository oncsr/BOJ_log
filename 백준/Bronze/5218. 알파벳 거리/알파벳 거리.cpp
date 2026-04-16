#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    for(cin>>T;T--;){
        string A, B;
        cin>>A>>B;
        cout<<"Distances: ";
        for(int i=0;i<A.size();i++){
            char x = A[i], y = B[i];
            if(y >= x)  cout<<int(y-x)<<' ';
            else    cout<<int(y+26-x)<<' ';
        }
        cout<<'\n';
    }

}