#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    string S;
    int A, B;
    for(cin>>S>>A>>B;S != "#";cin>>S>>A>>B){
        cout<<S<<' '<<(A>17 || B>=80 ? "Senior\n" : "Junior\n");
    }

}