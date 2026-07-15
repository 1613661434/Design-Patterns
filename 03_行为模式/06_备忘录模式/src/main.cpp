#include "Memento.hpp"
#include "Recorder.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> msg{
        "不承认偷了中国的中医!!!",
        "不承认发动了侵华战争!!!",
        "不承认南京大屠杀!!!!",
        "不承认琉球群岛和钓鱼岛是中国的领土!!!",
        "不承认731部队的细菌和人体试验!!!",
        "不承认对我国妇女做出畜生行为!!!",
        "不承认从中国掠夺的数以亿计的资源和数以万计的文物!!!",
        "我干的龌龊事儿罄竹难书, 就是不承认......"
    };
    JiaoPenJi* jiaopen = new JiaoPenJi;
    Recorder* recorder = new Recorder;
    // 把小日本的罪行记录下来
    for (std::size_t i = 0; i < msg.size(); ++i)
    {
        jiaopen->setState(msg.at(i));
        recorder->addHistory(static_cast<int>(i), jiaopen->saveHistory());
    }
    jiaopen->beiDaddyDa();
    for (std::size_t i = 0; i < msg.size(); ++i)
    {
        jiaopen->getStateFromHistory(recorder->getHistory(static_cast<int>(i)));
        std::cout << "  -- " << jiaopen->getState() << std::endl;
    }
    delete jiaopen;
    delete recorder;
    return 0;
}
