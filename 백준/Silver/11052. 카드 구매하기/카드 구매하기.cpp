#include <iostream>
using namespace std;
int main(){
    int n,d[1000]{};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
        for(int j=0;j<(i+1)/2;j++)
            d[i]=max(d[i],d[j]+d[i-j-1]);
    }
    cout<<d[n-1];
}