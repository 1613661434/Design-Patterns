#pragma once

#include <iostream>
#include <string>

// =============================================================================
// 适配器模式 (Adapter Pattern) - 海贼王主题: 乔巴翻译官
// =============================================================================
// 场景: 熊猫与外国人交流。熊猫只能理解特定格式的消息，而外国人(美国人、法国人)
// 使用不同的语言接口。通过适配器(乔巴翻译官)将外国人的表达转换为熊猫能理解
// 的格式，同时将熊猫的回应翻译给外国人。

// ---------------------------------------------------------------------------
// Adaptee: 需要被适配的接口 - 外国人
// ---------------------------------------------------------------------------
class Foreigner {
public:
    virtual std::string confession() = 0;
    void setResult(const std::string& msg) {
        std::cout << "Panda Say: " << msg << std::endl;
    }
    virtual ~Foreigner() {}
};

// 美国人
class American : public Foreigner {
public:
    std::string confession() override {
        return std::string("我是畜生, 我有罪!!!");
    }
};

// 法国人
class French : public Foreigner {
public:
    std::string confession() override {
        return std::string("我是强盗, 我该死!!!");
    }
};

// ---------------------------------------------------------------------------
// Target: 客户端期望的接口 - 大熊猫
// ---------------------------------------------------------------------------
class Panda {
public:
    void recvMessage(const std::string& msg) {
        std::cout << msg << std::endl;
    }
    std::string sendMessage() {
        return std::string("强盗、凶手、罪人是不可能被宽恕和原谅的！");
    }
};

// ---------------------------------------------------------------------------
// Adapter: 抽象乔巴适配器类
// ---------------------------------------------------------------------------
class AbstractChopper {
public:
    AbstractChopper(Foreigner* foreigner) : m_foreigner(foreigner) {}
    virtual void translateToPanda() = 0;
    virtual void translateToHuman() = 0;
    virtual ~AbstractChopper() {}
protected:
    Panda m_panda;
    Foreigner* m_foreigner = nullptr;
};

// 英语乔巴适配器: 连接Panda与American
class EnglishChopper : public AbstractChopper {
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override {
        std::string msg = m_foreigner->confession();
        m_panda.recvMessage("美国人说: " + msg);
    }
    void translateToHuman() override {
        std::string msg = m_panda.sendMessage();
        m_foreigner->setResult("美国佬, " + msg);
    }
};

// 法语乔巴适配器: 连接Panda与French
class FrenchChopper : public AbstractChopper {
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override {
        std::string msg = m_foreigner->confession();
        m_panda.recvMessage("法国人说: " + msg);
    }
    void translateToHuman() override {
        std::string msg = m_panda.sendMessage();
        m_foreigner->setResult("法国佬, " + msg);
    }
};
