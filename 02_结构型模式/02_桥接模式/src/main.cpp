#include "AbstractShip.hpp"
#include "Person.hpp"
using namespace std;

int main() {
    // =========================================================================
    // 场景1: 草帽海贼团登上梅利号
    // =========================================================================
    CaoMaoTeam* caomao = new CaoMaoTeam("草帽海贼团");
    Person* luffy = new Person("路飞", "船长", "橡胶果实能力者", "30亿贝里", "爱吃肉");
    Person* zoro = new Person("索隆", "剑士", "三刀流", "11亿1100万贝里", "路痴");
    Person* sanji = new Person("山治", "厨师", "隐形黑", "10亿3200万贝里", "好色");
    Person* nami = new Person("娜美", "航海士", "天候棒+宙斯", "3亿6600万贝里", "喜欢钱");
    caomao->addMember(luffy);
    caomao->addMember(zoro);
    caomao->addMember(sanji);
    caomao->addMember(nami);

    Merry* sunny = new Merry(caomao);
    sunny->feature();
    sunny->showTeam();

    cout << "=====================================" << "\n";

    // =========================================================================
    // 场景2: 斯摩格部队登上海军号
    // =========================================================================
    SmokerTeam* team = new SmokerTeam("斯摩格的海军部队");
    Person* smoker = new Person("斯摩格", "中将", "冒烟果实能力者", "", "爱吃烟熏鸡肉");
    Person* dasiqi = new Person("达斯琪", "大佐", "一刀流", "", "近视");
    team->addMember(smoker);
    team->addMember(dasiqi);

    HaiJunShip* ship = new HaiJunShip(team);
    ship->feature();
    ship->showTeam();

    cout << "================== 资源释放 ==================" << "\n";

    // 注意: Person由AbstractTeam析构函数负责释放
    // AbstractShip不负责释放AbstractTeam (由调用者管理)
    delete sunny;
    delete ship;
    delete caomao;  // 释放草帽团队(含所有Person)
    delete team;    // 释放斯摩格部队(含所有Person)

    return 0;
}
