#include"../include/sha256.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cassert>

using namespace SHA;
using namespace BINARY;
const array<ui32,64> Sha256::K = {
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
		0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
		0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
		0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
		0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
		0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
		0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
		0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
		0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
		0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
		0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
		0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

Sha256::Sha256():_textSize{0},_textSizeBits{0},_block{0},_wBlock{0},_hash{0}
{}

void Sha256::Init()
{
	_hash[0] = 0x6a09e667;
	_hash[1] = 0xbb67ae85;
	_hash[2] = 0x3c6ef372;
	_hash[3] = 0xa54ff53a;
	_hash[4] = 0x510e527f;
	_hash[5] = 0x9b05688c;
	_hash[6] = 0x1f83d9ab;
	_hash[7] = 0x5be0cd19;
}

//process the text to get a 64bytes array
void Sha256::Block(string::const_iterator const& it_begin, string::const_iterator const& it_end)
{
	size_t const partsize = std::distance(it_begin, it_end);
//std::cout<<"distance: "<<partsize<<"\n";
	assert(partsize < 65);
	std::fill(_block.begin(), _block.end(), 0);
	if (partsize < 64 && partsize!=0) _block[partsize] = 0x80;
	if (partsize < (_blockSize - 8))
	{
		std::copy(it_begin, it_end, _block.begin());
		//unpack from 64 to 8
		*(_block.end()-1) = _textSizeBits;
		*(_block.end()-2) = _textSizeBits >> 8;
		*(_block.end()-3) = _textSizeBits >> 16;
		*(_block.end()-4) = _textSizeBits >> 24;
		*(_block.end()-5) = _textSizeBits >> 32;
		*(_block.end()-6) = _textSizeBits >> 40;
		*(_block.end()-7) = _textSizeBits >> 48;
		*(_block.end()-8) = _textSizeBits >> 56;
	}
	else
	{
		std::copy(it_begin, it_end, _block.begin());
	}
//for(auto const& i : _block)
//	cout<<int(i)<<" ";
//cout<<"\n partsize:" << partsize<<"\n";

	this->WBlock();
	this->Transform();
}

//transform _block of 8bit*64 array into a _wblock of 32bit*64
void Sha256::WBlock()
{
//cout<<"PARSING"<<"\n";
	for(size_t i = 0, j=0; i < 16; i++, j+=4)
	{
		_wBlock[i] = (_block[j] << 24 | _block[j+1] << 16 | _block[j+2] << 8 | _block[j+3] );
	}
	for(size_t i = 16; i < 64; i++)
	{
		_wBlock[i] = SIGMA1(_wBlock[i-2]) + _wBlock[i-7] + SIGMA0(_wBlock[i-15]) + _wBlock[i-16];
	}
//for(auto const& i : _wBlock)
//	std::cout<<i<<" ";
//cout<<"\n";
}

//Blockation
void Sha256::Transform()
{
	ui32 a{_hash[0]}
		,b{_hash[1]}
		,c{_hash[2]}
		,d{_hash[3]}
		,e{_hash[4]}
		,f{_hash[5]}
		,g{_hash[6]}
		,h{_hash[7]}
		,T1{0} ,T2{0};
	
	for(size_t i=0; i<64; i++)
	{
		T1 = h + USIGMA1(e) + CH(e,f,g) + K[i] + _wBlock[i];
		T2 = USIGMA0(a) + MAJ(a, b, c);
		h = g;
		g = f;
		f = e;
		e = d + T1;
		d = c;
		c = b;
		b = a;
		a = T1 + T2;
	}
	
	_hash[0] += a;
	_hash[1] += b;
	_hash[2] += c;
	_hash[3] += d;
	_hash[4] += e;
	_hash[5] += f;
	_hash[6] += g;
	_hash[7] += h;
}

void Sha256::Comput(string const& text)
{
	_textSize = text.size();
	_textSizeBits = _textSize*8;
//std::cout<<"textsize: "<<_textSize<<" bits: "<<_textSizeBits<<" ";
	const size_t nb64rep = _textSize/64;
	const size_t diff = _textSize - nb64rep*64;
	//nb64rep+=((_textSize - nb64rep*64) <= 55)? 0:1;
//std::cout<<"diff: "<<_textSize - nb64rep*64<<" ";
//std::cout<<"nb64rep: "<<nb64rep<<" ";
	size_t delta = 0;
	//Block each segment of text
	for(size_t i=0; i <= nb64rep; ++i)
	{
		auto start = text.cbegin()+i*delta;
		delta = (i<nb64rep)? 64:_textSize - nb64rep*64;
//std::cout<<"delta: "<<delta<<"\n";
		auto end = (delta < 64)? text.end():start+delta;
		Block(start, end);
	}
	if (diff > 55) //if the last part of the text is sup to 55 we nee to add another block
	{
		Block(text.end(), text.end());
	}
}

//SHA operations
string Sha256::Sha(string const& text)
{
	this->Init();
	this->Comput(text);
	stringstream ss;
	for(auto const& i: _hash)
		ss<<std::setfill ('0') << std::setw(sizeof(_hash[0])*2)<<std::hex<<i;
//	std::cout<<ss.str();

	return ss.str();
}