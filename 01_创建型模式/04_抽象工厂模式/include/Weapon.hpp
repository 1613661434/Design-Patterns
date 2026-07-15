#pragma once

#include <string>

// ============================================================================
// 产品族: 武器 (Weapon)
// ============================================================================

// 抽象武器产品
class Weapon
{
public:
    virtual std::string getWeapon() = 0;
    virtual ~Weapon() = default;
};

// 具体产品：枪
class Gun : public Weapon
{
public:
    std::string getWeapon() override
    {
        return std::string("配备的武器是<枪>...");
    }
};

// 具体产品：自动机关炮
class Cannon : public Weapon
{
public:
    std::string getWeapon() override
    {
        return std::string("配备的武器是<自动机关炮>...");
    }
};

// 具体产品：激光
class Laser : public Weapon
{
public:
    std::string getWeapon() override
    {
        return std::string("配备的武器是<激光>...");
    }
};
