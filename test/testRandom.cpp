#include "random.hpp"
#include <iostream>

int main()
{
    lgd::Random<512> rand;
    auto randData = rand.getRand();
    for(auto const& i : randData)
        std::cout<<int(i)<<" ";
    std::cout<<"\n";
    return 0;
}