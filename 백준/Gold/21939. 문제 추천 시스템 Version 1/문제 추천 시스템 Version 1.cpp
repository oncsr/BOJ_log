#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int lev[100001]{};
    int N;
    cin>>N;
    
    set<int> arr[101]{};
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        lev[a] = b;
        arr[b].insert(a);
    }
    
    int M;
    for(cin>>M;M--;){
        string op;
        int x, y;
        cin>>op>>x;
        if(op == "add"){
            cin>>y;
            lev[x] = y;
            arr[y].insert(x);
        }
        else if(op == "solved"){
            int lv = lev[x];
            lev[x] = 0;
            arr[lv].erase(x);
        }
        else{
            int v;
            if(x == 1){
                for(int i=100;i>0;i--){
                    if(arr[i].empty())  continue;
                    v = *arr[i].rbegin();
                    break;
                }
            }
            else{
                for(int i=1;i<=100;i++){
                    if(arr[i].empty())  continue;
                    v = *arr[i].begin();
                    break;
                }
            }
            cout<<v<<'\n';
        }
    }
    
}