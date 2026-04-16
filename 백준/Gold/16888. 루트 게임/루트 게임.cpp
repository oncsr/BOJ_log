#include <iostream>
#include <bitset>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    bitset<1000001> D;
    for(int i=1;i<=1000000;i++){
        for(int j=1;j*j<=i;j++) if(!D[i-j*j]) D[i] = 1;
    }

    int T;
    for(cin>>T;T--;){
        int a;
        cin>>a;
        if(D[a]) cout<<"koosaga\n";
        else cout<<"cubelover\n";
    }

}