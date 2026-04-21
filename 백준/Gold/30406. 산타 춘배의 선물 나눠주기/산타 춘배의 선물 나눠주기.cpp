#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int zero = 0, one = 0, two = 0, three = 0, N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        if(a == 0)  zero++;
        if(a == 1)  one++;
        if(a == 2)  two++;
        if(a == 3)  three++;
    }

    int g1 = min(zero, three), g2 = min(one, two);
    int ans = (g1+g2)*3;
    zero -= g1, three -= g1;
    one -= g2, two -= g2;
    if(zero){
        if(one){
            int g3 = min(zero, one);
            ans += g3;
        }
        else{
            int g3 = min(zero, two);
            ans += g3*2;
        }
    }
    else{
        if(one){
            int g3 = min(one, three);
            ans += g3*2;
        }
        else{
            int g3 = min(two, three);
            ans += g3;
        }
    }
    cout<<ans;
}