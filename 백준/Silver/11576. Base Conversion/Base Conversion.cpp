#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int A, B, m, a = 0;
    cin>>A>>B>>m;
    int arr[25]{};
    for(int i=0;i<m;i++)    cin>>arr[i];
    int g = 1;
    for(int i=m-1;i>=0;i--){
        a += arr[i] * g;
        g *= A;
    }
    stack<int> S;
    while(a){
        S.push(a%B);
        a = (a-(a%B)) / B;
    }
    while(!S.empty())   cout<<S.top()<<' ', S.pop();

}