#include "Visitor.hpp"
#include "Member.hpp"
#include "CaoMaoTeam.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// ============ Anger 成员函数实现 ============

void Anger::maleDoing(MaleMember* male)
{
    std::cout << "我是草帽海贼团的" << male->getName() << std::endl;
    fight();
}

void Anger::femalDoing(FemaleMember* female)
{
    std::cout << "我是草帽海贼团的" << female->getName() << std::endl;
    warning();
}

void Anger::warning()
{
    std::cout << "大家块逃，我快顶不住了, 不要管我!!!" << std::endl;
}

void Anger::fight()
{
    std::cout << "只要还活着就得跟这家伙血战到底!!!" << std::endl;
}

// ============ Horror 成员函数实现 ============

void Horror::maleDoing(MaleMember* male)
{
    std::cout << "我是草帽海贼团的" << male->getName() << std::endl;
    thinking();
}

void Horror::femalDoing(FemaleMember* female)
{
    std::cout << "我是草帽海贼团的" << female->getName() << std::endl;
    help();
}

void Horror::help()
{
    std::cout << "这个大熊太厉害, 太可怕了, 快救救我。。。" << std::endl;
}

void Horror::thinking()
{
    std::cout << "得辅助同伴们一块攻击这个家伙, 不然根本打不过呀!!!" << std::endl;
}

// ============ main ============

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    std::vector<std::string> names{
        "路飞", "索隆","山治", "乔巴", "弗兰奇", "乌索普", "布鲁克"
    };
    CaoMaoTeam* caomao = new CaoMaoTeam;
    for (const auto& item : names)
    {
        caomao->add(new MaleMember(item));
    }
    caomao->add(new FemaleMember("娜美"));
    caomao->add(new FemaleMember("罗宾"));
    caomao->display();
    delete caomao;
    return 0;
}
