#include<iostream>
main(){int T,n,d[7]={0,0,0,0,2,1,0};for(std::cin>>T;T--;){std::cin>>n;std::cout<<(n>6?1:d[n])<<'\n';}}