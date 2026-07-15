#pragma once

#include "NewsAgency.hpp"

// 摩根斯的新闻社
class Morgans : public NewsAgency
{
public:
    void notify(std::string msg) override;
};

// 八卦新闻
class Gossip : public NewsAgency
{
public:
    void notify(std::string msg) override;
};
