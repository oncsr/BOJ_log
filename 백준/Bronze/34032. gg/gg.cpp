#include <iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    int s = 0;
    for(int i=0;i<N;i++) {
        char a;
        cin>>a;
        s += a == 'O' ? 1 : -1;
    }
    cout<<(s >= 0 ? "Yes" : "No");
}