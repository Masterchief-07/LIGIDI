#pragma once
#include<array>
#include <algorithm>
#include <cassert>
namespace lgd
{
template<size_t SIZE>
class UInt
{
    static_assert(SIZE % 8 == 0);
    static constexpr size_t _size = SIZE/8;
    std::array<uint8_t, _size>_data;
    
    public:
    UInt();
    UInt(std::string const& text);

    uint8_t operator[](size_t pos) const { return _data[pos];}
    uint8_t& operator[](size_t pos){ return _data[pos];}

    auto begin() { return _data.begin();}
    auto begin() const { return _data.cbegin();}
    auto cbegin() const { return _data.cbegin();}
    auto end() { return _data.end();}
    auto end() const { return _data.cend();}
    auto cend() const { return _data.cend();}
    size_t size() const { return _data.size();}

};

template<size_t SIZE>
UInt<SIZE>::UInt():_data{0}
{}

template<size_t SIZE>
UInt<SIZE>::UInt(std::string const& text)
{
    assert(text.size() == _data.size());
    std::copy(text.begin(), text.end(), _data.begin());
}




}