#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int x1, x2, a, b, c, d, e;
    cin>>x1>>x2>>a>>b>>c>>d>>e;
    cout<<a/3*(x2*x2*x2-x1*x1*x1)+(b-d)/2*(x2*x2-x1*x1)+(c-e)*(x2-x1);

}