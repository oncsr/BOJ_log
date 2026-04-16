#include <bits/stdc++.h>
using namespace std;

int palace[3][3] = 
{
    {0,1,2},
    {1,2,0},
    {2,0,1}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    int P = 0;
    for(;n--;){
        int x,y;
        cin>>x>>y;
        P ^= ((x/3)^(y/3))*3 + palace[x%3][y%3];
    }
    cout<<(P?"koosaga":"cubelover");

}