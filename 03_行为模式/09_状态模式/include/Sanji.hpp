#pragma once

class AbstractState;
class ForenoonState;

class Sanji
{
public:
    Sanji()
    {
        m_state = new ForenoonState;
    }
    void working()
    {
        m_state->working(this);
    }
    void setState(AbstractState* state)
    {
        if (m_state != nullptr)
        {
            delete m_state;
        }
        m_state = state;
    }
    void setClock(int time)
    {
        m_clock = time;
    }
    int getClock()
    {
        return m_clock;
    }
    ~Sanji()
    {
        delete m_state;
    }
private:
    int m_clock = 0;    // 时钟
    AbstractState* m_state = nullptr;
};
