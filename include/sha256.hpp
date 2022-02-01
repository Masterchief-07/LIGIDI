#pragma once
#include <cstdint>
#include <cassert>
namespace SHA
{
	using ui8 = uint8_t; 
	using ui32 = uint32_t; 
	using ui64 = uint64_t;
	
	constexpr ui32 SHFR(ui32 const& x, ui8 const& n) 
	{
		assert(n<32);
		return x>>n;
	}
	constexpr ui32 SHFL(ui32 const& x, ui8 const& n) 
	{
		assert(n<32);
		return x<<n;
	}
	


	class Sha256
	{
		Sha256();		




	};//class SHA256
};//namespace
