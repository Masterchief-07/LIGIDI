#pragma once
#include <cstdint>
#include <cassert>
#include "binary.hpp"
#include <array>
namespace SHA
{
	using ui8 = uint8_t; 
	using ui32 = uint32_t; 
	using ui64 = uint64_t;
	using namespace std;
	class Sha256
	{
		private:
			const size_t _blockSize{64};
			size_t _textSize, _textSizeBits;
			static const array<ui32,64> K;
			array<ui8, 64> 	_block;
			array<ui32, 64> _wBlock;
			array<ui32, 8>	_hash;

		public:
			Sha256();
			void Init();
			void Comput(string const& text);
			void Block(string::const_iterator const& it_begin, string::const_iterator const& it_end);
			void WBlock();
			void Transform();
			string Sha(string const& text);


	};//class SHA256
};//namespace
