#pragma once

#include "Country.hpp"

// 卡玛巴卡王国
class Kamabaka : public Country
{
public:
    using Country::Country;
    void declare(std::string msg, std::string country) override;
    void setMessage(std::string msg) override;
    std::string getName() override;
};
