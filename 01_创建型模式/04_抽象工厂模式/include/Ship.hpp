#pragma once

#include "ShipBody.hpp"
#include "Weapon.hpp"
#include "Engine.hpp"
#include <string>

// ============================================================================
// 产品族容器: 战船 (Ship)
// 聚合了船体、武器、动力三个产品族的产品
// ============================================================================
class Ship
{
public:
    Ship(ShipBody* body, Weapon* weapon, Engine* engine)
        : m_body(body), m_weapon(weapon), m_engine(engine)
    {
    }

    std::string getProperty()
    {
        std::string info = m_body->getShipBody()
                         + m_weapon->getWeapon()
                         + m_engine->getEngine();
        return info;
    }

    ~Ship()
    {
        delete m_body;
        delete m_weapon;
        delete m_engine;
    }

private:
    ShipBody* m_body = nullptr;
    Weapon* m_weapon = nullptr;
    Engine* m_engine = nullptr;
};
