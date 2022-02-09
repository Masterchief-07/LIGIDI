#include "uintbase.hpp"
#include <iostream>
int main()
{
    lgd::UInt<32> base{};
    std::cout<<"test1: default init : OK\n";
    std::string hex{"A4"};
    lgd::UInt<16> base16{hex};
    std::cout<<"test2: string init : OK\n";
    for(auto const& i: base16)
        std::cout<<i;
    std::cout<<"\n";
    std::cout<<"test3: print data : OK\n";
    int j = 0;
    for(size_t i=0; i < base.size(); i++)
    {
        base[i] = j;
        std::cout<<int(base[i])<<" ";
        ++j;
    }
    std::cout<<"\n";
    std::cout<<"test4: set data value: OK\n";



    return 0;
}