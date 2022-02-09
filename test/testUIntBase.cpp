#include "uintbase.hpp"
#include <iostream>
int main()
{
    lgd::UIntBase<16> base{};
    std::cout<<"test1: default init : OK\n";
    std::string hex{"A4"};
    lgd::UIntBase<16> base16{hex};
    std::cout<<"test2: string init : OK\n";
    for(auto const& i: base16)
        std::cout<<i;
    std::cout<<"\n";
    std::cout<<"test3: print data : OK\n";


    return 0;
}