#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
    cout<<(((n&1)&&(m&1))?'B':'A');

}