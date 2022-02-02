#pragma once
#include <cstdint>
using ui8 = uint8_t; 
using ui32 = uint32_t; 
using ui64 = uint64_t;
//base binary operations
namespace BINARY
{
template<typename T>
constexpr T SHFR(T const& x, ui8 const& n)  //shift right
{
    assert(n < (sizeof(T)*8));
    return x >> n;
}
template<typename T> 
constexpr T SHFL(T const& x, ui8 const& n) //shift left
{
    assert(n < (sizeof(T)*8));
    return x<<n;
}
template<typename T> 
constexpr T RTR(T const& x, ui8 const& n) //rotation right
{
    return ((x >> n) | (x << ((sizeof(x) << 3) - n)));
}
template<typename T> 
constexpr T RTL(T const& x, ui8 const& n) //rotation left
{
    return ((x << n) | (x >> ((sizeof(x) << 3) - n)));
}

template<typename T> 
constexpr T SIGMA0(T const& x)      //sha operation 1
{
    return RTR(x, 7) ^ RTR(x, 18) ^ SHFR(x, 3);
}

template<typename T> 
constexpr T SIGMA1(T const& x)      //sha operation 2
{
    return RTR(x, 17) ^ RTR(x, 19) ^ SHFR(x, 10);
}

template<typename T> 
constexpr T USIGMA0(T const& x)      //sha operation 3
{
    return RTR(x, 2) ^ RTR(x, 13) ^ RTR(x, 22);
}

template<typename T> 
constexpr T USIGMA1(T const& x)      //sha operation 4
{
    return RTR(x, 6) ^ RTR(x, 11) ^ RTR(x, 25);
}

template<typename T> 
constexpr T CH(T const& x, T const& y, T const& z)      //sha operation 5
{
    return ((x & y) ^ (~x & z));
}

template<typename T>
constexpr T MAJ(T const& x, T const& y, T const& z)      //sha operation 6
{
    return ((x & y) ^ (x & z) ^ (y & z));
}

}//BINARY namespace

