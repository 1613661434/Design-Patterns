#pragma once

#include "Country.hpp"

// 阿拉巴斯坦
class Alabasta : public Country
{
public:
    using Country::Country;
    void declare(std::string msg, std::string country) override;
    void setMessage(std::string msg) override;
    std::string getName() override;
};
