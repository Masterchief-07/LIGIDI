#pragma once
#include <cstdint>
#include <cassert>
namespace SHA
{
	using ui8 = uint8_t; 
	using ui32 = uint32_t; 
	using ui64 = uint64_t;
	template<typename T> 
	constexpr T SHFR(T const& x, ui8 const& n) 
	{
		assert(n < (sizeof(T)*8));
		return x>>n;
	}
	template<typename T> 
	constexpr T SHFL(T const& x, ui8 const& n) 
	{
		assert(n < (sizeof(T)*8));
		return x<<n;
	}
	template<typename T> 
	constexpr T RTR(T const& x, ui8 const& n)
	{
		return (x >> n) | (x << ((sizeof(x) << 3) - n));
	}
	template<typename T> 
	constexpr T RTL(T const& x, ui8 const& n)
	{
		return (x << n) | (x >> ((sizeof(x) << 3) - n));
	}
	class Sha256
	{
		Sha256();		




	};//class SHA256
};//namespace
