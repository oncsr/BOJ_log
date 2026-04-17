#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S;
    cin>>S;
    int ans = 1e9;
    // an의 길이
    for(int len=1;len<=9 && S.size() > len;len++){
        if(S[S.size()-len] == '0')  continue;
        int an = stoi(S.substr(S.size()-len,len));
        // an-1의 길이
        for(int len2=1;len2<=9 && S.size() > len + len2;len2++){
            if(S[S.size()-len-len2] == '0') continue;
            int an1 = stoi(S.substr(S.size()-len-len2, len2));
            if(an % an1 || an == an1)    continue;
            for(int len3=1;len3<=9 && S.size() >= len+len2+len3;len3++){
                if(S[S.size()-len-len2-len3] == '0')    continue;
                int an2 = stoi(S.substr(S.size()-len-len2-len3,len3));
                if(an2 >= an1)   continue;
                int d = an1-an2;
                int cut = len+len2+len3;
                
                bool chk = 1;
                while(cut < S.size()){
                    int next = an2 - d;
                    if(next <= 0)   {chk = 0;break;}
                    string temp = to_string(next);
                    if(temp.size() + cut > S.size())   {chk = 0;break;}
                    if(S.substr(S.size()-temp.size()-cut,temp.size()) != temp)  {chk = 0;break;}
                    cut += temp.size();
                    an2 = next;
                }
                if(chk) ans = min(ans, an/an1);

            }
        }
    }
    cout<<(ans == 1e9 ? 0 : ans);
 
}