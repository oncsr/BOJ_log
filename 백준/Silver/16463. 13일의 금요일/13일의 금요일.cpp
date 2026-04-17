#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, s = 0;
    cin>>N;
    int G = 1, ans = 0;
    // 0 ~ 6
    int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int year = 2019;year <= N;year++){
        for(int month = 1;month <= 12;month++){
            if(G == 6)  ans++;
            if(month == 2){
                if(year % 400 == 0) G += 29;
                else {
                    if(year % 100 == 0)    G += 28;
                    else if(year % 4 == 0)  G += 29;
                    else    G += 28;
                }
            }
            else    G += arr[month];
            G %= 7;
        }
    }
    cout<<ans;
    
}