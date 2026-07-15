#pragma once

#include "Observer.hpp"

// 革命军龙
class Dragon : public Observer
{
public:
    using Observer::Observer;
    void update(std::string msg) override;
};

// 红发香克斯
class Shanks : public Observer
{
public:
    using Observer::Observer;
    void update(std::string msg) override;
};

// 巴托洛米奥
class Bartolomeo : public Observer
{
public:
    using Observer::Observer;
    void update(std::string msg) override;
};
