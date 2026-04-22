#include<iostream>
using namespace std;main(){int K,G,g;cin>>K;G=K%9,g=(K-9)/9;string b="";for(;g--;)b+='9';if(G>1)cout<<-1;else{cout<<(G?"19"+b+"\n55"+b+"\n73"+b:"9"+b+"\n27"+b+"\n36"+b);}}