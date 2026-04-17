#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string a;
    cin>>a;
    stack<int> S;
    for(int i=a.size()-1;i>=0;i-=3){
        int b = a[i] - '0';
        if(i-1 >= 0)    b += 2*(a[i-1] - '0');
        if(i-2 >= 0)    b += 4*(a[i-2] - '0');
        S.push(b);
    }
    while(!S.empty())   cout<<S.top(), S.pop();

}