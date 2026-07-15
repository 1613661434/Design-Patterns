#include "Adapter.hpp"
using namespace std;

int main() {
    // 场景1: 美国人通过英语乔巴与熊猫交流
    Foreigner* human = new American;
    EnglishChopper* american = new EnglishChopper(human);
    american->translateToPanda();
    american->translateToHuman();
    delete human;
    delete american;

    cout << "===================================" << endl;

    // 场景2: 法国人通过法语乔巴与熊猫交流
    human = new French;
    FrenchChopper* french = new FrenchChopper(human);
    french->translateToPanda();
    french->translateToHuman();
    delete human;
    delete french;

    return 0;
}
