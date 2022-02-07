/**
 * @file block.hpp
 * @author your name (Masterchief-07)
 * @brief 
 * @version 0.1
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/**
 * block contain transactions for the blockchain'
 * it keep the transactions data, prevblockHash, the hash 
*/
#include<string>
#include <vector>
namespace SHA
{
    using namespace std;
class Block
{   
    private:
        std::string _prevHash;
        std::string _hash;
        uint32_t _once;
        std::string _header;

    public:

};

};