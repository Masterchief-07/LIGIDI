#pragma once
#include<array>
#include <algorithm>
#include <cassert>
namespace lgd
{
template<size_t SIZE>
class UIntBase
{
    static constexpr size_t _size = SIZE/8;
    std::array<uint8_t, _size>_data;
    
    public:
    UIntBase();
    UIntBase(std::string const& text);

    auto begin() { return _data.begin();}
    auto begin() const { return _data.cbegin();}
    auto cbegin() const { return _data.cbegin();}
    auto end() { return _data.end();}
    auto end() const { return _data.cend();}
    auto cend() const { return _data.cend();}
    size_t size() const { return _data.size();}

};

template<size_t SIZE>
UIntBase<SIZE>::UIntBase():_data{0}
{}

template<size_t SIZE>
UIntBase<SIZE>::UIntBase(std::string const& text)
{
    assert(text.size() == _data.size());
    std::copy(text.begin(), text.end(), _data.begin());
}




}