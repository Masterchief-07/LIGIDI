//#include"../include/sha256.hpp"
#include"sha256.hpp"
#include<iostream>
#include<cassert>
using namespace SHA;
int main()
{
	//test shift right
	assert(SHFR(11, 1) == ui32(5));
	std::cout<<"shift right OK"<<"\n";
	//test shift left
	assert(SHFL(11, 1) == ui32(22));
	std::cout<<"shift left OK"<<"\n";

	return 0;
}
