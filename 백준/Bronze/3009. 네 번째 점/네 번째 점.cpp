#import<iostream>
main(){int a=0,b=0,c,d,i=3;for(;i--;)std::cin>>c>>d,a^=c,b^=d;std::cout<<a<<' '<<b;}