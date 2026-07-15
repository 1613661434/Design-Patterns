#include "Manager.hpp"

void Manager::handleRequest(RequestType type)
{
    switch (type)
    {
    case RequestType::QingJia:
        std::cout << "请假: 同意请假，好好休息~~~" << std::endl;
        break;
    case RequestType::ZhangXin:
        std::cout << "涨薪: 这个我得请示一下咱们CEO..." << " ====> ";
        m_next->handleRequest(type);
        break;
    case RequestType::CiZhi:
        std::cout << "辞职: 我给你向上级反应一下..." << " ====> ";
        m_next->handleRequest(type);
        break;
    default:
        break;
    }
}

void CEO::handleRequest(RequestType type)
{
    switch (type)
    {
    case RequestType::QingJia:
        std::cout << "请假: 同意请假, 下不为例..." << std::endl;
        break;
    case RequestType::ZhangXin:
        std::cout << "涨薪: 你工资不少了, 给你个购物券吧..." << std::endl;
        break;
    case RequestType::CiZhi:
        std::cout << "辞职: 这个我得问问咱们老板..." << " ====> ";
        m_next->handleRequest(type);
        break;
    default:
        break;
    }
}

void Boss::handleRequest(RequestType type)
{
    switch (type)
    {
    case RequestType::QingJia:
        std::cout << "请假: 只有工作才能实现人生价值，回去好好坚守岗位！！！" << std::endl;
        break;
    case RequestType::ZhangXin:
        std::cout << "涨薪: 钱财乃身外之物, 要视其如粪土!!!" << std::endl;
        break;
    case RequestType::CiZhi:
        std::cout << "辞职: 巴洛克工作社就是你的家, 这次把你留下, 下次别再提了!!!" << std::endl;
        break;
    default:
        break;
    }
}

int main()
{
    Manager* manager = new Manager;
    CEO* ceo = new CEO;
    Boss* boss = new Boss;
    // 设置关联关系
    manager->setNext(ceo);
    ceo->setNext(boss);

    // 卑微的大聪明的请求
    DaCongMing* boy = new DaCongMing;
    std::cout << "========== 大聪明向顶头上司提要求 ==========" << std::endl;
    boy->request(RequestType::QingJia, manager);
    boy->request(RequestType::ZhangXin, manager);
    boy->request(RequestType::CiZhi, manager);
    std::cout << "========== 大聪明越级找CEO提要求 ==========" << std::endl;
    boy->request(RequestType::QingJia, ceo);
    boy->request(RequestType::ZhangXin, ceo);
    boy->request(RequestType::CiZhi, ceo);
    std::cout << "========== 大聪明直接找BOSS提要求 ==========" << std::endl;
    boy->request(RequestType::QingJia, boss);
    boy->request(RequestType::ZhangXin, boss);
    boy->request(RequestType::CiZhi, boss);

    delete boy;
    delete manager;
    delete ceo;
    delete boss;

    return 0;
}
