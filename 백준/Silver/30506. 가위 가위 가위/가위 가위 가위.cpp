#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int K;
    cin>>K;
    string ans = "";
    for(int i=0;i<100;i++){
        cout<<"? ";
        for(int j=0;j<100;j++){
            if(i == j)  cout<<'0';
            else    cout<<'2';
        }
        cout<<endl;
        int p;
        cin>>p;
        if(p == K-1)    ans += '5';
        else if(p == K) ans += '0';
        else    ans += '2';
    }
    cout<<"! "<<ans<<endl;

}