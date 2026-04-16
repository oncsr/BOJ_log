#include <bits/stdc++.h>
using namespace std;

int N, P = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    if(N >= 1000000) P = N/100*20;
    else if(N >= 500000) P = N/100*15;
    else if(N >= 100000) P = N/100*10;
    else P = N/100*5;
    cout<<P<<' '<<N-P;

}