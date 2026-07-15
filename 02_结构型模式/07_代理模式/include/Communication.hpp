#pragma once

#include <iostream>
#include <string>

// =============================================================================
// 代理模式 (Proxy Pattern) - 海贼王主题: 电话虫
// =============================================================================
// 场景: 电话虫作为代理，模仿通话者的语言和表情。客户端通过电话虫间接进行
// 交流，电话虫在原始通话(Speaker)的基础上添加"实时模仿"的功能。

// ---------------------------------------------------------------------------
// Subject (抽象接口): 通信接口
// ---------------------------------------------------------------------------
class Communication {
public:
    virtual void communicate() = 0;
    virtual ~Communication() {}
};

// ---------------------------------------------------------------------------
// Real Subject (原始对象): 讲话的人
// ---------------------------------------------------------------------------
class Speaker : public Communication {
public:
    void communicate() override {
        std::cout << "开始说话..." << std::endl;
        std::cout << "通话时发生了一些列的表情变化..." << std::endl;
    }
};

// ---------------------------------------------------------------------------
// Proxy (代理对象): 电话虫
// ---------------------------------------------------------------------------
// 持有Speaker引用，在原始通话功能基础上添加实时模仿功能。
class DenDenMushi : public Communication {
public:
    DenDenMushi() {
        m_isStart = true;
        m_speaker = new Speaker;
    }

    ~DenDenMushi() {
        if (m_speaker != nullptr) {
            delete m_speaker;
        }
    }

    bool isStart() const {
        return m_isStart;
    }

    void communicate() override {
        if (isStart()) {
            // 代理在调用原始对象之前添加额外逻辑: 实时模仿
            std::cout << "电话虫开始实时模仿通话者的语言和表情..." << std::endl;
            m_speaker->communicate();
        }
    }

private:
    bool m_isStart = false;
    Speaker* m_speaker = nullptr;
};
