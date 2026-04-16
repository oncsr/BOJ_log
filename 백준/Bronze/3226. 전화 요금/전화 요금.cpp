#include <bits/stdc++.h>
using namespace std;

int main(){
    int s = 0, N;
    for(cin>>N;N--;){
        int a,b,c;
        char _;
        cin>>a>>_>>b>>c;
        int st = a*60+b, ed = st+c;
        for(int i=st;i<ed;i++){
            if(420 <= (i%1440) && (i%1440) < 1140)   s += 10;
            else    s += 5;
        }
    }
    cout<<s;
}