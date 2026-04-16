#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N,A,B,a=1,b=1;
    cin>>N>>A>>B;
    for(int i=0;i<N;i++){
        a += A, b += B;
        if(a < b)   swap(a,b);
        else if(a == b) b--;
    }
    cout<<a<<' '<<b;
    
}