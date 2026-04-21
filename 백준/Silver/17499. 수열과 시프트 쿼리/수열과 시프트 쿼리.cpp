#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin>>N>>Q;
    int arr[200000]{};
    for(int i=0;i<N;i++)   cin>>arr[i];

    int s = 0;
    for(;Q--;){
        int o, a, b;
        cin>>o>>a;
        if(o == 1){
            a--;
            cin>>b;
            arr[(a+s)%N] += b;
        }
        else{
            if(o == 3)  s += a;
            else    s += (N-a);
            s %= N;
        }
    }
    for(int i=0;i<N;i++)   cout<<arr[(i+s)%N]<<' ';

}