#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int k, l, n, cont = 0, use = 0, no = 0;
    cin>>k>>l>>n;
    int f = 0;
    for(int i=1;i<=n;i++){
        char a;
        cin>>a;
        if(a == '1'){
            if(use){
                no = 0;
                continue;
            }
            cont++;
            if(cont == k){
                use = 1;
                cont = 0;
            }
        }
        else{
            if(use){
                no++;
                if(no == l){
                    f++;
                    cout<<i<<'\n';
                    use = 0;
                    no = 0;
                }
            }
            else{
                cont = 0;
            }
        }
    }
    if(use){
        cout<<n+l-no;
        f++;
    }
    if(!f)  cout<<"NIKAD";
}