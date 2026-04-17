#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    for(cin>>T;T--;){
        int m = 0, z = 0;
        for(int i=0;i<10;i++){
            int a;
            cin>>a;
            if(a == 18) m++;
            if(a == 17) z++;
            cout<<a<<' ';
        }
        cout<<'\n';
        if(m && z)  cout<<"both\n";
        else if(m)  cout<<"mack\n";
        else if(z)  cout<<"zack\n";
        else    cout<<"none\n";
        cout<<'\n';
    }

}