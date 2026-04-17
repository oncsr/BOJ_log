#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int arr[1001]{}, N, Q;
    cin>>N;
    for(int i=1;i<=N;i++)   cin>>arr[i];
    for(cin>>Q;Q--;){
        int a,b,c,d;
        cin>>a>>b>>c;
        if(a == 1){
            cin>>d;
            int cnt = 0;
            for(int j=b;j<=c;j++)   cnt += (arr[j] == d);
            cout<<cnt<<'\n';
        }
        else{
            for(int j=b;j<=c;j++)   arr[j] = 0;
        }
    }
}