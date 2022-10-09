#include<iostream>
main(){int a[10]{},i=10;std::string b;std::cin>>b;for(char i:b)a[i-48]++;for(;i--;)while(a[i]--)std::cout<<i;}