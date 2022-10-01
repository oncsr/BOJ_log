#include<iostream>
main(){long long n;while(std::cin>>n){long long i=2,r=n;while(i*i<=n){if (!(n%i)){while(!(n%i))n/=i;r*=(1-1.0/i);}i++;}if(n>1){r*=(1-1.0/n);}std::cout<<r/2<<'\n';}}