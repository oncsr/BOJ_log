#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);

    int Q;
    for(cin>>Q;Q--;){
        string a;
        cin>>a;
        int res = 0;
        for(int i=0;i<int(a.size())-2;i++){
            if(a.substr(i,3) == "WOW")  res++;
        }
        cout<<res<<'\n';
    }

}