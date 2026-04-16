#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    string a,b="◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!",c="흥칫뿡!! <(￣ ﹌ ￣)>";
    cin>>a;
    if(a.size() == 1)   cout<<b;
    else{
        int d = a[1]-a[0];
        for(int i=2;i<a.size();i++){
            if(a[i] - a[i-1] != d)  return cout<<c,0;
        }
        cout<<b;
    }

}