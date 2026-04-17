#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    for(cin>>T;T--;){
        vector<int> A, B, C;
        int a, b, c, d;
        for(cin>>a;a--;){
            cin>>d;
            A.push_back(d);
        }
        for(cin>>b;b--;){
            cin>>d;
            B.push_back(d);
        }
        for(cin>>c;c--;){
            cin>>d;
            C.push_back(d);
        }
        int ans = 0;
        set<int> S;
        for(int i:A){
            for(int j:B){
                for(int k:C){
                    string s = to_string(i+j+k);
                    bool r = 1;
                    for(char x:s){
                        if(x != '5' && x != '8')    r = 0;
                    }
                    if(r)   S.insert(i+j+k);
                }
            }
        }
        cout<<S.size()<<'\n';
    }

}