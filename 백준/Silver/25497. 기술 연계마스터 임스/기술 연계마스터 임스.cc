#include<iostream>
using namespace std;
int main(){int r=0,k=0,s=0;string a,n;cin>>n>>a;for(char i:a){if((!r&&i==82)||(!k&&i==75))break;if(i>48&&i<58)s++;if(i==82){s++;r--;}if(i==75){s++;k--;}if(i==76)r++;if(i==83)k++;}cout<<s;}