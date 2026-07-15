#pragma once

#include "Country.hpp"

// 露露西亚王国
class Lulusia : public Country
{
public:
    using Country::Country;
    void declare(std::string msg, std::string country) override;
    void setMessage(std::string msg) override;
    std::string getName() override;
};
