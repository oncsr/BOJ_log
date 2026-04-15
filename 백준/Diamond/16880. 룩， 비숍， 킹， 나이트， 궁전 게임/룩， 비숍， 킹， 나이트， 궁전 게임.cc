#include <bits/stdc++.h>
using namespace std;

int rook[4][4] = 
{
    {0,1,2,3},
    {1,0,3,2},
    {2,3,0,1},
    {3,2,1,0}
};

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
    int R = 0, B = 0, K = 0, N = 0, P = 0;
    for(;n--;){
        int x,y;
        char a;
        cin>>x>>y>>a;
        if(a == 'R')    R ^= ((x/4)^(y/4))*4 + rook[x%4][y%4];
        if(a == 'B')    B ^= min(x,y);
        if(a == 'K'){
            int g;
            if(x == y)  g = ((x&1)?2:0);
            else{
                if(x < y)   swap(x,y);
                if(x&1) g = ((y&1)?2:1);
                else    g = ((y&1)?3:0);
            }
            K ^= g;
        }
        if(a == 'N'){
            int g;
            if(x == y)  g = (x%3==2?1:0);
            else{
                if(x < y)   swap(x,y);
                if(y%3 == 2)    g = (y+1==x?1:2);
                else    g = y%3;
            }
            N ^= g;
        }
        if(a == 'P')    P ^= ((x/3)^(y/3))*3 + palace[x%3][y%3];
    }
    int x = R^B^K^N^P;
    cout<<(x?"koosaga":"cubelover");

}