#pragma once

// 前向声明
class MaleMember;
class FemaleMember;

// 抽象的动作类 - 访问者
class AbstractAction
{
public:
    // 访问男人
    virtual void maleDoing(MaleMember* male) = 0;
    // 访问女人
    virtual void femalDoing(FemaleMember* female) = 0;
    virtual ~AbstractAction() {}
};

// 愤怒
class Anger : public AbstractAction
{
public:
    void maleDoing(MaleMember* male) override;
    void femalDoing(FemaleMember* female) override;
    void warning();
    void fight();
};

// 恐惧
class Horror : public AbstractAction
{
public:
    void maleDoing(MaleMember* male) override;
    void femalDoing(FemaleMember* female) override;
    void help();
    void thinking();
};
