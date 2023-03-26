#include<iostream>
#include<algorithm>
int main(){std::string s,t;std::cin>>s>>t;int p=t.size(),g=s.size();int c=p-g;while(p>=g){if(t[p]=='B')std::reverse(t.begin(),t.begin()+p);p--;}t.erase(p+1,c);std::cout<<(s==t);}