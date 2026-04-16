#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    string a;
    int A=0,B=0,C=0;
    for(int i=0;i<3;i++){
        cin>>a;
        if(a[0] == 'l') A++;
        if(a[0] == 'k') B++;
        if(a[0] == 'p') C++;
    }
    cout<<(A&&B&&C ? "GLOBAL":"PONIX");
    
}