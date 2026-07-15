#pragma once

#include "Country.hpp"

// 德雷斯罗萨
class Dressrosa : public Country
{
public:
    using Country::Country;
    void declare(std::string msg, std::string country) override;
    void setMessage(std::string msg) override;
    std::string getName() override;
};
