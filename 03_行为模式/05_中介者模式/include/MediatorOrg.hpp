#pragma once

#include <string>
#include <map>

class Country;

// 抽象的中介机构
class MediatorOrg
{
public:
    void addMember(Country* country);
    virtual void declare(std::string msg, Country* country, std::string name = std::string()) = 0;
    virtual ~MediatorOrg() {}
protected:
    std::map<std::string, Country*> m_countryMap;
};
