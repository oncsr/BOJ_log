#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    string ans;
    if(n < 425) ans = "Violet";
    else if(n < 450)    ans = "Indigo";
    else if(n < 495)    ans = "Blue";
    else if(n < 570)    ans = "Green";
    else if(n < 590)    ans = "Yellow";
    else if(n < 620)    ans = "Orange";
    else    ans = "Red";
    cout<<ans;

}