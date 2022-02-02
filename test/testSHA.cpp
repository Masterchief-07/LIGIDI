//#include"../include/sha256.hpp"
#include"sha256.hpp"
#include<iostream>
#include<cassert>
using namespace SHA;
int main()
{
	//test shift right
	assert(SHFR(ui32(0x05), 1) == ui32(0x02));
	std::cout<<"shift right OK"<<"\n";
	//test shift left
	assert(SHFL(ui32(0x05), 1) == ui32(0x0a));
	std::cout<<"shift left OK"<<"\n";
	//test rotate right
	assert(RTR(ui8(0x07), 1) == ui8(0x83));
	std::cout<<"rotation right OK"<<"\n";
	//test rotate left
	assert(RTL(ui8(0x80), 1) == ui8(0x01));
	std::cout<<"rotation left OK"<<"\n";

	return 0;
}
