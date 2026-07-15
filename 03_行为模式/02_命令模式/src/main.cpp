#include "Command.hpp"
#include "Waiter.hpp"

int main()
{
    CookerZeff* cooker = new CookerZeff;
    WaiterLuffy* luffy = new WaiterLuffy;

    YXRSCommand* yxrs = new YXRSCommand(cooker);
    GBJDCommand* gbjd = new GBJDCommand(cooker);
    DSXCommand* dsx = new DSXCommand(cooker);
    HSPGCommand* hspg = new HSPGCommand(cooker);

    std::cout << "=================== 开始点餐 ===================" << std::endl;
    luffy->setOrder(1, yxrs);
    luffy->setOrder(1, dsx);
    luffy->setOrder(1, gbjd);
    luffy->setOrder(1, hspg);
    luffy->setOrder(2, dsx);
    luffy->setOrder(2, gbjd);
    luffy->setOrder(2, hspg);
    std::cout << "=================== 撤销订单 ===================" << std::endl;
    luffy->cancelOrder(1, dsx);
    std::cout << "=================== 开始烹饪 ===================" << std::endl;
    luffy->notify(1);
    luffy->notify(2);
    std::cout << "=================== 结账 ===================" << std::endl;
    luffy->checkOut(1);
    luffy->checkOut(2);

    delete yxrs;
    delete gbjd;
    delete dsx;
    delete hspg;
    delete luffy;
    delete cooker;

    return 0;
}
