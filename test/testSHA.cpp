//#include"../include/sha256.hpp"
#include"sha256.hpp"
#include<iostream>
#include<cassert>
#include <bitset>

using namespace SHA;
using namespace BINARY;

int main()
{
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

//test SHA lib
	Sha256 sha;
	std::string test{"abc"};
	assert(sha.Sha(test) == "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");
	std::cout<<"SHA TEST1 : OK"<<"\n";
	test = "abcdefghijklmnopqrstuvwxyz-abcdefghijklmnopqrstuvwxyz-abcdefghijklmnopqrstuvwxyz";
	assert(sha.Sha(test) == "9948de85a44aca196f4689728fef8edbdb0520ec6eec0fd2d25b09a71228dd85");
	std::cout<<"SHA TEST2 : OK"<<"\n";
	test = "abcdefghijklmnopqrstuvwxyz-abcdefghijklmnopqrstuvwxyz-abcdefghijklmnopqrstuvwxyz-abcdefghijklmnopqrstuvwxyz-abcdefghijkl";
	assert(sha.Sha(test) == "04ccef6c541148a8d468d1f5100af4d29e6f051cb7736e3c0ced0bdb503d0650");
	std::cout<<"SHA TEST3 : OK"<<"\n";
	test = "kiendrebeogo jonathan";
	assert(sha.Sha(test) == "f263c338690e7343a3a580fea62e7b0085b9ba9d2390c5bcefa65d574b2065eb");
	std::cout<<"SHA TEST4 : OK"<<"\n";
	test = "I can find some ways to do it, but they mostly seem targeted towards C. It doesn't seem there's a native way to do it in C++. It is a pretty simple problem though; I've got an int which I'd like to convert to a hex string for later printing.";
	assert(sha.Sha(test) == "ec1da18ba957f7c5bc27c9236501926d11d2386eabb40a982641835aa525aeca");
	std::cout<<"SHA TEST5 : OK"<<"\n";
	test = "https://www.google.com/search?q=test+sh256&rlz=1C5CHFA_enBF920BF920&oq=test+sh256&aqs=chrome..69i57j0i8i10i13i30.2909j0j7&sourceid=chrome&ie=UTF-8";
	assert(sha.Sha(test) == "895312e581002551b2897005624cbf53edb57c50312d1a06938fd47017e558ab");
	std::cout<<"SHA TEST6 : OK"<<"\n";


	return 0;
}
