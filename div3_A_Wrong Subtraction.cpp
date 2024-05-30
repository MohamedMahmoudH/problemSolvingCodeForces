#include<iostream>
main(){int k,n;std::cin>>n>>k;while(k--)n%10?n--:n/=10;std::cout<<n;}
