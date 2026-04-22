#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, l = 0, r = 0, u = 0, d = 0;
    ii arr[500001]{};
    cin>>n;
    for(int i=0;i<n;i++)    cin>>arr[i].first>>arr[i].second;
    int a, b;
    cin>>a>>b;
    for(int i=0;i<n;i++){
        int x = arr[i].first;
        int y = arr[i].second;
        if(a == x){
            if(b > y)    d++;
            else     u++;
        }
        else if(b == y){
            if(a > x)    l++;
            else     r++;
        }
        else{
            int dx = abs(a-x);
            int dy = abs(b-y);
            if(a > x && b > y){
                if(dx == dy)    l++, d++;
                else if(dx > dy)    l++;
                else     d++;
            }
            else if(a > x){
                if(dx == dy)    l++, u++;
                else if(dx > dy)    l++;
                else     u++;
            }
            else if(b > y){
                if(dx == dy)    r++, d++;
                else if(dx > dy)    r++;
                else     d++;
            }
            else{
                if(dx == dy)    r++, u++;
                else if(dx > dy)    r++;
                else     u++;
            }
        }
    }
    if(l&&r&&u&&d)    cout<<"NO";
    else     cout<<"YES";
}