#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin>>N;
    int s = 1, e = N, d = (e-s+1)/3;
    while(e-s > 1){
        int m1 = s+d-1, m2 = s+2*d-1;
        cout<<"? ";
        for(int i=s;i<=m1;i++)  cout<<i<<' ';
        cout<<"0 ";
        for(int i=m1+1;i<=m2;i++) cout<<i<<' ';
        cout<<"0 "<<endl;

        char r;
        cin>>r;
        if(r == '=')    s = m2+1;
        else if(r == '>')   s = m1+1, e = m2;
        else    e = m1;
        d = (e-s+1)/3;
    }
    if(s == e)  cout<<"! "<<s<<endl;
    else{
        cout<<"? "<<s<<" 0 "<<e<<" 0 "<<endl;
        char r;
        cin>>r;
        if(r == '>')    cout<<"! "<<e<<endl;
        else    cout<<"! "<<s<<endl;
    }

}