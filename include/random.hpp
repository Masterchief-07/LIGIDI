#pragma once
/**
 its generate random value
 use specialy when creating private and public key
 */

#include <cstdlib>
#include <ctime>
#include <uintbase.hpp>


namespace lgd
{
template<size_t SIZE>       //size of the random number return
class Random
{
    UInt<SIZE> _seed;
    UInt<SIZE> _data;
    void _randSeed();       //creation de seed aleatoir
    public:
    Random();
    UInt<SIZE> getRand();

};

template<size_t SIZE> 
Random<SIZE>::Random()
{
    srand(time(NULL));
    this->getRand();
}

template<size_t SIZE> 
UInt<SIZE> Random<SIZE>::getRand()
{
    this->_randSeed();
    size_t j = 0;
    for(uint8_t& i: _data)
    {
        srand(_seed[j]);
        i = rand() % 256;
        j++;
    }
    return _data;
}
template<size_t SIZE> 
void Random<SIZE>::_randSeed()
{
    for(auto& i: _seed)
    {
        i = rand() %256;
    }
}

};

