#import<iostream>
main(){char a;for(;std::cin>>a;){int n=a,s=0;for(;n;s+=n%10,n/=10);for(;s--;std::cout<<a);std::cout<<'\n';}}