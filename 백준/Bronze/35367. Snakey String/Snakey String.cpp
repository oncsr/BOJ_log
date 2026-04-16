#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[10000]{};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
        char a;
        cin>>a;
        if(a != '.') {
            arr[j] = a;
        }
    }
    for(int i=0;i<M;i++) cout<<arr[i];
    
}