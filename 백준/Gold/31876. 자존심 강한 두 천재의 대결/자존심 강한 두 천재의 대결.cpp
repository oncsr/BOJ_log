#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int A, B;
    cin>>A>>B;
    string a, b;
    cin>>a>>b;
    if(A == B)  cout<<(a == b ? "rasauq" : (a > b ? "ras" : "auq"));
    else{
        if(a.size() > 24)   cout<<(A > B ? "ras" : "auq");
        else{
            __int128 aa = 0, bb = 0, g = 1;
            for(int i=a.size()-1;i>=0;i--){
                aa += (a[i]-'0') * g;
                g *= A;
            }
            g = 1;
            for(int i=b.size()-1;i>=0;i--){
                bb += (b[i]-'0') * g;
                g *= B;
            }
            cout<<(aa == bb ? "rasauq" : (aa > bb ? "ras" : "auq"));
        }
    }
 
}
