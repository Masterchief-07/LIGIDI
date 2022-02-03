//#include"../include/sha256.hpp"
#include"sha256.hpp"
#include<iostream>
#include<cassert>
#include <bitset>

using namespace SHA;
using namespace BINARY;

int main()
{
	//test SHA lib
	Sha256 sha;
	//std::string abc{"abcasdbasdhbajbslkuhavsdkjhvasjdhvasghvdjahsvdkjavdkjahsvdkjhajsdvjahvsdjhavsdhjvajskdhvajkhsdvjkahsvdjk"};
	std::string abc{"abc"};
	//sha.Preprocessing(abc.begin(), abc.end());
	std::string abc2{"abcdefghijklmnopqrstuvwxyz-abcdefghijklmnopqrstuvwxyz-abcdefghijklmnopqrstuvwxyz"};
	std::string abc3{"abcdefghijklmnopqrstuvwxyz-abcdefghijklmnopqrstuvwxyz-abcdefghijklmnopqrstuvwxyz-abcdefghijklmnopqrstuvwxyz-abcdefghijkl"};
	sha.Sha(abc);
cout<<"\n";
	//sha.Sha(abc2);
cout<<"\n";
	//sha.Sha(abc3);

	//test shift right
	//std::cout<<std::bitset<32>{0x05}<<"\t"<<std::bitset<32>{0x02}<<"\n";
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

	//test sha function 1
	ui32 x = 0x3FFF;
	//std::cout<<std::bitset<32>{x}<<"\t"<<std::bitset<32>{SIGMA0(ui32(0x00003FFF))}<<"\n";
	assert(SIGMA0(x) == ui32(0xF1FFc780));
	std::cout<<"SHA SIGMA0 OK"<<"\n";

	//test sha function 2
	//std::cout<<std::bitset<32>{x}<<"\t"<<std::bitset<32>{SIGMA1(ui32(0x00003FFF))}<<"\n";
	assert(SIGMA1(x) == ui32(0x1800600F));
	std::cout<<"SHA SIGMA1 OK"<<"\n";

	//test sha function 3
	//std::cout<<std::bitset<32>{x}<<"\t"<<std::bitset<32>{USIGMA0(ui32(0x00003FFF))}<<"\n";
	assert(USIGMA0(x) == ui32(0x3F07F3FE));
	std::cout<<"SHA USIGMA0 OK"<<"\n";

	//test sha function 4
	//std::cout<<std::bitset<32>{x}<<"\t"<<std::bitset<32>{USIGMA1(ui32(0x00003FFF))}<<"\n";
	assert(USIGMA1(x) == ui32(0x03FFFF78));
	std::cout<<"SHA USIGMA1 OK"<<"\n";

	//test sha function 4
	x = 0x00FF00FF;
	ui32 y = 0xFFFF, z = 0xFFFF0000;
	//std::cout<<std::bitset<32>{x}<<"\t"<<std::bitset<32>{USIGMA1(ui32(0x00003FFF))}<<"\n";
	assert(CH(x,y,z) == ui32(0xFF0000FF));
	std::cout<<"SHA CH OK"<<"\n";

	//test sha function 4
	//std::cout<<std::bitset<32>{x}<<"\t"<<std::bitset<32>{USIGMA1(ui32(0x00003FFF))}<<"\n";
	assert(MAJ(x,y,z) == ui32(0x00FF00FF));
	std::cout<<"SHA MAJ OK"<<"\n";


	return 0;
}
