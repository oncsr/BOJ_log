#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, K, temp, cnt = 1;
    cin>>N>>K>>temp;
    for(int i=1;i<N;i++){
        int a;
        cin>>a;
        if(temp + K >= a)   continue;
        cnt++;
        temp = a;
    }
    cout<<cnt;
}