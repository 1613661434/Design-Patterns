#pragma once

#include "MediatorOrg.hpp"

class Country;

// 世界政府
class WorldGovt : public MediatorOrg
{
public:
    void declare(std::string msg, Country* country, std::string name = std::string()) override;
};
