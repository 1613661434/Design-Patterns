#pragma once

#include "MediatorOrg.hpp"

class Country;

// 革命军
class GeMingArmy : public MediatorOrg
{
public:
    void declare(std::string msg, Country* country, std::string name = std::string()) override;
};
