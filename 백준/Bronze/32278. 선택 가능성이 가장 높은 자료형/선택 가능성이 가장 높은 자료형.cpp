#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    long long N;
    cin>>N;
    if(-32768 <= N && N <= 32767)   cout<<"short";
    else if(INT_MIN <= N && N <= INT_MAX)   cout<<"int";
    else    cout<<"long long";

}