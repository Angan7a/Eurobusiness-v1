#pragma once

#include "Property.hpp"

class Railway : public Property
{
public:
    Railway() = default;
    Railway(const std::string & name, int purchasePrice = 100);
};
