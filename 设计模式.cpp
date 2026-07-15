#pragma region 设计模式
// VS2022编辑器打开，可以适配编辑器自带的折叠功能
// 具体文章：https://subingwen.cn/design-patterns/#1-%E5%89%8D%E8%A8%80
// 类之间的关系强弱顺序是这样的：继承（泛化） >  组合  >  聚合  >  关联  >  依赖。

#pragma region 创建型模式
// 单例模式（Singleton Pattern）
/*
//单例模式是一种创建型设计模式，确保一个类只有一个实例，并提供一个全局访问点来获取这个实例。
//常用于需要全局唯一对象的场景，如配置管理器、数据库连接池、任务队列等。

//结构组成：
//单例类：负责创建自己的唯一实例，并提供全局访问方法

//实现方式：
//单例模式分为两种主要实现方式：
//1. 饿汉模式（Eager Initialization）
//特点：类加载时立即创建实例，线程安全
//优点：实现简单，无需考虑线程同步问题
//缺点：可能造成资源浪费（即使未使用实例也会创建）
//2. 懒汉模式（Lazy Initialization）
//特点：首次使用时才创建实例
//优点：避免资源浪费
//缺点：需处理多线程并发问题

//示例场景：
//给巴基的账本升级成一个应用程序，首要任务就是设计一个单例模式的多线程安全任务队列，那么就需要赋予这个类一些属性和方法：

//属性：
//存储任务的容器，这个容器可以选择使用STL中的队列（queue)
//互斥锁，多线程访问的时候用于保护任务队列中的数据

//方法：主要是对任务队列中的任务进行操作
//任务队列中任务是否为空
//往任务队列中添加一个任务
//从任务队列中取出一个任务
//从任务队列中删除一个任务

#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
using namespace std;

class TaskQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator=(const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        return &m_obj;
    }
    // 任务队列是否为空
    bool isEmpty()
    {
        lock_guard<mutex> locker(m_mutex);
        bool flag = m_taskQ.empty();
        return flag;
    }
    // 添加任务
    void addTask(int data)
    {
        lock_guard<mutex> locker(m_mutex);
        m_taskQ.push(data);
    }
    // 取出一个任务
    int takeTask()
    {
        lock_guard<mutex> locker(m_mutex);
        if (!m_taskQ.empty())
        {
            return m_taskQ.front();
        }
        return -1;
    }
    // 删除一个任务
    bool popTask()
    {
        lock_guard<mutex> locker(m_mutex);
        if (!m_taskQ.empty())
        {
            m_taskQ.pop();
            return true;
        }
        return false;
    }
private:
    TaskQueue() = default;
    static TaskQueue m_obj;
    queue<int> m_taskQ;
    mutex m_mutex;
};
TaskQueue TaskQueue::m_obj;

int main()
{
    thread t1([]() {
        TaskQueue* taskQ = TaskQueue::getInstance();
        for (int i = 0; i < 100; ++i)
        {
            taskQ->addTask(i + 100);
            cout << "+++push task: " << i + 100 << ", threadID: "
                << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        });
    thread t2([]() {
        TaskQueue* taskQ = TaskQueue::getInstance();
        this_thread::sleep_for(chrono::milliseconds(100));
        while (!taskQ->isEmpty())
        {
            int data = taskQ->takeTask();
            cout << "---take task: " << data << ", threadID: "
                << this_thread::get_id() << endl;
            taskQ->popTask();
            this_thread::sleep_for(chrono::seconds(1));
        }
        });
    t1.join();
    t2.join();
}

// 下面这种更好，通过静态函数和静态变量（懒汉模式）
class S {
public:
    string s;

    // 全局访问点，返回唯一实例的引用
    static S& getInstance() {
        static S instance;  // 静态局部变量，第一次调用时初始化，保证唯一性
        return instance;
    }

private:
    // 私有构造函数，禁止外部创建实例
    S() {};

    // 禁止复制和赋值
    S(const S&) = delete;
    S& operator=(const S&) = delete;
};
*/

// 简单工厂模式（Simple Factory Pattern）并不属于规范的设计模式
/*
//简单工厂模式是一种创建型设计模式，它提供了一种创建对象的方式，将对象的创建和使用分离。
//通过一个工厂类来负责创建产品对象，客户端只需通过参数向工厂类请求所需产品，而无需直接实例化对象。

//结构组成：
//抽象产品类：定义产品的公共接口（如AbstractSmile）
//具体产品类：实现抽象产品接口的具体产品（如SheepSmile、LionSmile、BatSmile）
//工厂类：负责根据参数创建具体产品对象（如SmileFactory）

//示例场景：
//设计一个恶魔果实工厂，根据不同类型生产对应的恶魔果实能力者。每个果实能力者可以进行变身并释放特殊技能。

#include <iostream>
using namespace std;

class AbstractSmile
{
public:
    virtual void transform() {}
    virtual void ability() {}
    virtual ~AbstractSmile() {}
};

// 人造恶魔果实· 绵羊形态
class SheepSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "变成人兽 -- 山羊人形态..." << endl;
    }
    void ability() override
    {
        cout << "将手臂变成绵羊角的招式 -- 巨羊角" << endl;
    }
};

// 人造恶魔果实· 狮子形态
class LionSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "变成人兽 -- 狮子人形态..." << endl;
    }
    void ability() override
    {
        cout << "火遁· 豪火球之术..." << endl;
    }
};

class BatSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "变成人兽 -- 蝙蝠人形态..." << endl;
    }
    void ability() override
    {
        cout << "声纳引箭之万剑归宗..." << endl;
    }
};

// 恶魔果实工厂类
enum class Type :char { SHEEP, LION, BAT };
class SmileFactory
{
public:
    SmileFactory() {}
    ~SmileFactory() {}
    AbstractSmile* createSmile(Type type)
    {
        AbstractSmile* ptr = nullptr;
        switch (type)
        {
        case Type::SHEEP:
            ptr = new SheepSmile;
            break;
        case Type::LION:
            ptr = new LionSmile;
            break;
        case Type::BAT:
            ptr = new BatSmile;
            break;
        default:
            break;
        }
        return ptr;
    }
};

int main()
{
    SmileFactory* factory = new SmileFactory;
    AbstractSmile* obj = factory->createSmile(Type::BAT);
    obj->transform();
    obj->ability();
    return 0;
}
*/

// 工厂模式（Factory Method Pattern）
/*
//工厂方法模式是一种创建型设计模式，它定义了一个创建对象的接口，但让子类决定实例化哪个类。
//工厂方法模式将对象的创建延迟到子类，使得子类可以灵活决定创建何种产品对象。

//结构组成：
//抽象产品类：定义产品的公共接口（如AbstractSmile）
//具体产品类：实现抽象产品接口的具体产品（如SheepSmile、LionSmile、BatSmile）
//抽象工厂类：声明创建产品的抽象方法（如AbstractFactory）
//具体工厂类：实现抽象工厂的方法，负责创建具体产品（如SheepFactory、LionFactory、BatFactory）

//示例场景：
//扩展恶魔果实工厂，使每种果实形态都有专门的工厂类负责创建，遵循开闭原则，便于新增果实形态。

#include <iostream>
using namespace std;

class AbstractSmile
{
public:
    virtual void transform() = 0;
    virtual void ability() = 0;
    virtual ~AbstractSmile() {}
};
// 人造恶魔果实· 绵羊形态
class SheepSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "变成人兽 -- 山羊人形态..." << endl;
    }
    void ability() override
    {
        cout << "将手臂变成绵羊角的招式 -- 巨羊角" << endl;
    }
};

// 人造恶魔果实· 狮子形态
class LionSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "变成人兽 -- 狮子人形态..." << endl;
    }
    void ability() override
    {
        cout << "火遁· 豪火球之术..." << endl;
    }
};

class BatSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "变成人兽 -- 蝙蝠人形态..." << endl;
    }
    void ability() override
    {
        cout << "声纳引箭之万剑归宗..." << endl;
    }
};

// 恶魔果实工厂类
class AbstractFactory
{
public:
    virtual AbstractSmile* createSmile() = 0;
    virtual ~AbstractFactory() {}
};

class SheepFactory : public AbstractFactory
{
public:
    AbstractSmile* createSmile() override
    {
        return new SheepSmile;
    }
    ~SheepFactory()
    {
        cout << "释放 SheepFactory 类相关的内存资源" << endl;
    }
};

class LionFactory : public AbstractFactory
{
public:
    // 工厂函数
    AbstractSmile* createSmile() override
    {
        return new LionSmile;
    }
    ~LionFactory()
    {
        cout << "释放 LionFactory 类相关的内存资源" << endl;
    }

};

class BatFactory : public AbstractFactory
{
public:
    // 工厂函数
    AbstractSmile* createSmile() override
    {
        return new BatSmile;
    }
    ~BatFactory()
    {
        cout << "释放 BatFactory 类相关的内存资源" << endl;
    }
};

int main()
{
    AbstractFactory* factory = new BatFactory;
    AbstractSmile* obj = factory->createSmile();
    obj->transform();
    obj->ability();
    return 0;
}
*/

// 抽象工厂模式（Abstract Factory Pattern）
/*
//抽象工厂模式是一种创建型设计模式，它提供一个接口来创建一系列相关或相互依赖的对象，而无需指定它们具体的类。
//该模式将对象的创建和使用分离，客户端通过抽象接口操作产品，使具体实现对客户端透明。

//结构组成：
//抽象产品族：定义产品的抽象接口（如ShipBody、Weapon、Engine）
//具体产品：实现抽象产品接口的具体类（如WoodBody、Gun、Human）
//抽象工厂：声明创建抽象产品的方法（如AbstractFactory）
//具体工厂：实现抽象工厂的方法，创建具体产品族（如BasicFactory、StandardFactory）

//示例场景：
//设计一个战船生产系统，不同等级的工厂可以生产不同配置的战船（船体、武器、动力系统的组合）。

#include <iostream>
#include <string>
using namespace std;

// 船体
class ShipBody
{
public:
    virtual string getShipBody() = 0;
    virtual ~ShipBody() {}
};

class WoodBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("用<木材>制作轮船船体...");
    }
};

class IronBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("用<钢铁>制作轮船船体...");
    }
};

class MetalBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("用<合金>制作轮船船体...");
    }
};

// 武器
class Weapon
{
public:
    virtual string getWeapon() = 0;
    virtual ~Weapon() {}
};

class Gun : public Weapon
{
public:
    string getWeapon() override
    {
        return string("配备的武器是<枪>...");
    }
};

class Cannon : public Weapon
{
public:
    string getWeapon() override
    {
        return string("配备的武器是<自动机关炮>...");
    }
};

class Laser : public Weapon
{
public:
    string getWeapon() override
    {
        return string("配备的武器是<激光>...");
    }
};

// 动力
class Engine
{
public:
    virtual string getEngine() = 0;
    virtual ~Engine() {}
};

class Human : public Engine
{
public:
    string getEngine() override
    {
        return string("使用<人力驱动>...");
    }
};

class Diesel : public Engine
{
public:
    string getEngine() override
    {
        return string("使用<内燃机驱动>...");
    }
};

class Nuclear : public Engine
{
public:
    string getEngine() override
    {
        return string("使用<核能驱动>...");
    }
};

// 轮船类
class Ship
{
public:
    Ship(ShipBody* body, Weapon* weapon, Engine* engine) :
        m_body(body), m_weapon(weapon), m_engine(engine)
    {
    }
    string getProperty()
    {
        string info = m_body->getShipBody() + m_weapon->getWeapon() + m_engine->getEngine();
        return info;
    }
    ~Ship()
    {
        delete m_body;
        delete m_engine;
        delete m_weapon;
    }
private:
    ShipBody* m_body = nullptr;
    Weapon* m_weapon = nullptr;
    Engine* m_engine = nullptr;
};

// 工厂类
class AbstractFactory
{
public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory() {}
};

class BasicFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new WoodBody, new Gun, new Human);
        cout << "<基础型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class StandardFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new IronBody, new Cannon, new Diesel);
        cout << "<标准型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class UltimateFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new MetalBody, new Laser, new Nuclear);
        cout << "<旗舰型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

int main()
{
    AbstractFactory* factroy = new StandardFactory;
    Ship* ship = factroy->createShip();
    cout << ship->getProperty();
    delete ship;
    delete factroy;
    return 0;
}
*/

// 建造者模式/生成器（Builder Pattern）
/*
//建造者模式是一种创建型设计模式，它将复杂对象的构建与表示分离，使得同样的构建过程可以创建不同的表示。
//该模式适用于需要生成复杂对象（如组合多个部件或分步骤构建）的场景，通过将构建逻辑抽象化，允许客户端灵活控制对象的构造过程。

//结构组成
//抽象建造者（Builder）：定义构建产品各部分的接口（如ShipBuilder）。
//具体建造者（Concrete Builder）：实现抽象建造者的方法，构建产品的具体部件（如SunnyBuilder、MerryBuilder）。
//产品（Product）：被构建的复杂对象（如SunnyShip、MerryShip）。
//导演类（Director）：控制产品的构建流程，调用建造者的方法（如Director）。

//示例场景
//以《海贼王》中的船只建造为例，通过不同的建造者（桑尼号建造者、梅利号建造者）和导演类，分步骤构建不同类型的船只（船体、武器、动力系统、内室等部件）。

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 桑尼号
class SunnyShip
{
public:
    // 添加零件
    void addParts(string name)
    {
        m_parts.push_back(name);
    }
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            cout << item << "   ";
        }
        cout << endl;
    }
private:
    vector<string> m_parts;
};

// 梅利号
class MerryShip
{
public:
    // 组装
    void assemble(string name, string parts)
    {
        m_patrs.insert(make_pair(name, parts));
    }
    void showParts()
    {
        for (const auto& item : m_patrs)
        {
            cout << item.first << ": " << item.second << "  ";
        }
        cout << endl;
    }
private:
    map<string, string> m_patrs;
};

// 生成器类
class ShipBuilder
{
public:
    virtual void reset() = 0;
    virtual void buildBody() = 0;
    virtual void buildWeapon() = 0;
    virtual void buildEngine() = 0;
    virtual void buildInterior() = 0;
    virtual ~ShipBuilder() {}
};

// 桑尼号生成器
class SunnyBuilder : public ShipBuilder
{
public:
    SunnyBuilder()
    {
        reset();
    }
    ~SunnyBuilder()
    {
        if (m_sunny != nullptr)
        {
            delete m_sunny;
        }
    }
    // 提供重置函数, 目的是能够使用生成器对象生成多个产品
    void reset() override
    {
        m_sunny = new SunnyShip;
    }
    void buildBody() override
    {
        m_sunny->addParts("神树亚当的树干");
    }
    void buildWeapon() override
    {
        m_sunny->addParts("狮吼炮");
    }
    void buildEngine() override
    {
        m_sunny->addParts("可乐驱动");
    }
    void buildInterior() override
    {
        m_sunny->addParts("豪华内室精装");
    }
    SunnyShip* getSunny()
    {
        SunnyShip* ship = m_sunny;
        m_sunny = nullptr;
        return ship;
    }
private:
    SunnyShip* m_sunny = nullptr;
};

// 梅利号生成器
class MerryBuilder : public ShipBuilder
{
public:
    MerryBuilder()
    {
        reset();
    }
    ~MerryBuilder()
    {
        if (m_merry != nullptr)
        {
            delete m_merry;
        }
    }
    void reset() override
    {
        m_merry = new MerryShip;
    }
    void buildBody() override
    {
        m_merry->assemble("船体", "优质木材");
    }
    void buildWeapon() override
    {
        m_merry->assemble("武器", "四门大炮");
    }
    void buildEngine() override
    {
        m_merry->assemble("动力", "蒸汽机");
    }
    void buildInterior() override
    {
        m_merry->assemble("内室", "精装");
    }
    MerryShip* getMerry()
    {
        MerryShip* ship = m_merry;
        m_merry = nullptr;
        return ship;
    }
private:
    MerryShip* m_merry = nullptr;
};

// 主管类
class Director
{
public:
    void setBuilder(ShipBuilder* builder)
    {
        m_builder = builder;
    }
    // 简约型
    void builderSimpleShip()
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    // 标准型
    void builderStandardShip()
    {
        builderSimpleShip();
        m_builder->buildWeapon();
    }
    // 豪华型
    void builderRegalShip()
    {
        builderStandardShip();
        m_builder->buildInterior();
    }
private:
    ShipBuilder* m_builder = nullptr;
};

// 建造桑尼号
void builderSunny()
{
    Director* director = new Director;
    SunnyBuilder* builder = new SunnyBuilder;
    // 简约型
    director->setBuilder(builder);
    director->builderSimpleShip();
    SunnyShip* sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;

    // 标准型
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;

    // 豪华型
    builder->reset();
    director->setBuilder(builder);
    director->builderRegalShip();
    sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;
    delete builder;
    delete director;
}

// 建造梅利号
void builderMerry()
{
    Director* director = new Director;
    MerryBuilder* builder = new MerryBuilder;
    // 简约型
    director->setBuilder(builder);
    director->builderSimpleShip();
    MerryShip* merry = builder->getMerry();
    merry->showParts();
    delete merry;

    // 标准型
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    merry = builder->getMerry();
    merry->showParts();
    delete merry;

    // 豪华型
    builder->reset();
    director->setBuilder(builder);
    director->builderRegalShip();
    merry = builder->getMerry();
    merry->showParts();
    delete merry;
    delete builder;
    delete director;
}

int main()
{
    builderSunny();
    cout << "=====================================" << endl;
    builderMerry();
}
*/

// 原型模式（Prototype Pattern）
/*
//原型模式是一种创建型设计模式，它通过复制现有对象（原型）来创建新对象，而无需通过传统的构造函数调用。
//该模式适用于对象创建成本较高（如初始化耗时或资源密集）的场景，通过复制已有对象来提高性能和复用性。

//结构组成
//抽象原型（Prototype）：定义克隆自身的接口（如GermaSoldier）。
//具体原型（Concrete Prototype）：实现克隆方法，复制自身实例（如Soldier66、Soldier67）。

//示例场景
//以《海贼王》中杰尔马王国的超级士兵为例，通过原型模式复制已有的士兵对象，快速生成同类型的新士兵，避免重复初始化。

#include <iostream>
using namespace std;

class GermaSoldier
{
public:
    virtual GermaSoldier* clone() = 0;
    virtual string whoAmI() = 0;
    virtual ~GermaSoldier() {}
};

class Soldier66 : public GermaSoldier
{
public:
    GermaSoldier* clone() override
    {
        return new Soldier66(*this);
    }
    string whoAmI() override
    {
        return string("我是杰尔马66的超级士兵!!!");
    }
};

class Soldier67 : public GermaSoldier
{
public:
    GermaSoldier* clone()
    {
        return new Soldier67(*this);
    }
    string whoAmI() override
    {
        return string("我是杰尔马67的超级士兵!!!");
    }
};

int main()
{
    GermaSoldier* obj = new Soldier66;
    GermaSoldier* soldier = obj->clone();
    cout << soldier->whoAmI() << endl;
    delete soldier;
    delete obj;

    obj = new Soldier67;
    soldier = obj->clone();
    cout << soldier->whoAmI() << endl;
    delete soldier;
    delete obj;
}
*/
#pragma endregion

#pragma region 结构型模式
// 适配器模式（Adapter Pattern）
/*
//适配器模式是一种结构型设计模式，它允许将不兼容接口的类协同工作。
//通过创建一个中间适配器类，将一个类的接口转换为另一个接口，使原本因接口不兼容而无法合作的类可以一起工作。

//结构组成
//目标接口（Target）：客户端期望的接口（如Panda类的recvMessage和sendMessage方法）。
//适配者（Adaptee）：需要被适配的接口（如Foreigner及其子类American、French）。
//适配器（Adapter）：连接目标接口和适配者的中间类，实现目标接口并封装适配者（如AbstractChopper及其子类EnglishChopper、FrenchChopper）。

//示例场景
//以 “熊猫与外国人交流” 为例：熊猫只能理解特定格式的消息，而外国人（美国人、法国人）使用不同的语言接口。
//通过适配器（乔巴翻译官）将外国人的表达转换为熊猫能理解的格式，同时将熊猫的回应翻译给外国人。

#include <iostream>
#include <string>
using namespace std;

class Foreigner
{
public:
    virtual string confession() = 0;
    void setResult(string msg)
    {
        cout << "Panda Say: " << msg << endl;
    }
    virtual ~Foreigner() {}
};

// 美国人
class American : public Foreigner
{
public:
    string confession() override
    {
        return string("我是畜生, 我有罪!!!");
    }
};

// 法国人
class French : public Foreigner
{
public:
    string confession()
    {
        return string("我是强盗, 我该死!!!");
    }
};

// 大熊猫
class Panda
{
public:
    void recvMessage(string msg)
    {
        cout << msg << endl;
    }
    string sendMessage()
    {
        return string("强盗、凶手、罪人是不可能被宽恕和原谅的！");
    }
};

// 抽象乔巴适配器类
class AbstractChopper
{
public:
    AbstractChopper(Foreigner* foreigner) : m_foreigner(foreigner) {}
    virtual void translateToPanda() = 0;
    virtual void translateToHuman() = 0;
    virtual ~AbstractChopper() {}
protected:
    Panda m_panda;
    Foreigner* m_foreigner = nullptr;
};

// 英语乔巴适配器
class EnglishChopper : public AbstractChopper
{
public:
    // 继承构造函数
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override
    {
        string msg = m_foreigner->confession();
        // 翻译并将信息传递给熊猫对象
        m_panda.recvMessage("美国人说: " + msg);
    }
    void translateToHuman() override
    {
        // 接收熊猫的信息
        string msg = m_panda.sendMessage();
        // 翻译并将熊猫的话转发给美国人
        m_foreigner->setResult("美国佬, " + msg);
    }
};

// 法语乔巴适配器
class FrenchChopper : public AbstractChopper
{
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override
    {
        string msg = m_foreigner->confession();
        // 翻译并将信息传递给熊猫对象
        m_panda.recvMessage("法国人说: " + msg);
    }
    void translateToHuman() override
    {
        // 接收熊猫的信息
        string msg = m_panda.sendMessage();
        // 翻译并将熊猫的话转发给法国人
        m_foreigner->setResult("法国佬, " + msg);
    }
};

int main()
{
    Foreigner* human = new American;
    EnglishChopper* american = new EnglishChopper(human);
    american->translateToPanda();
    american->translateToHuman();
    delete human;
    delete american;

    human = new French;
    FrenchChopper* french = new FrenchChopper(human);
    french->translateToPanda();
    french->translateToHuman();
    delete human;
    delete french;

    return 0;
}
*/

// 桥接模式（Bridge Pattern）
/*
//桥接模式是一种结构型设计模式，它将抽象部分与实现部分分离，使两者可以独立变化。
//该模式通过 “组合” 而非 “继承” 的方式连接抽象和实现，避免多层继承导致的类爆炸问题，适用于需要将抽象和实现解耦的场景。

//结构组成
//抽象类（Abstraction）：定义抽象接口，持有实现部分的引用（如AbstractShip）。
//扩展抽象类（Refined Abstraction）：扩展抽象类的功能（如Merry、HaiJunShip）。
//实现接口（Implementor）：定义实现部分的接口（如AbstractTeam）。
//具体实现类（Concrete Implementor）：实现实现接口的具体功能（如CaoMaoTeam、SmokerTeam）。

//示例场景
//以《海贼王》中的船只与团队为例：船（如梅利号、海军舰）需要搭载不同的团队（草帽海贼团、斯摩格部队），
//通过桥接模式将 “船” 的抽象与 “团队” 的实现分离，使两者可以独立扩展（新增船只或团队时无需修改对方代码）。

#include <iostream>
#include <map>
using namespace std;

// 人员信息
struct Person
{
    Person(string name, string job, string ability, string reward, string biezhu = string())
    {
        this->name = name;
        this->job = job;
        this->ability = ability;
        this->reward = reward;
        this->beiZhu = biezhu;
    }
    ~Person()
    {
        cout << name << "被析构..." << endl;
    }
    string name;    // 名字
    string job;     // 职责
    string ability; // 能力
    string reward;  // 赏金
    string beiZhu;  // 备注
};

// 抽象船员
class AbstractTeam
{
public:
    AbstractTeam(string name) : m_teamName(name) {}
    string getTeamName()
    {
        return m_teamName;
    }
    void addMember(Person* p)
    {
        m_infoMap.insert(make_pair(p->name, p));
    }
    void show()
    {
        cout << m_teamName << ": " << endl;
        for (const auto& item : m_infoMap)
        {
            cout << "【Name: " << item.second->name
                << ", Job: " << item.second->job
                << ", Ability: " << item.second->ability
                << ", MoneyReward: " << item.second->reward
                << ", BeiZhu: " << item.second->beiZhu
                << "】" << endl;
        }
    }
    virtual void executeTask() = 0;   // 执行任务
    virtual ~AbstractTeam()
    {
        for (const auto& item : m_infoMap)
        {
            delete item.second;
        }
    }

protected:
    string m_teamName = string();
    map<string, Person*> m_infoMap;
};

class CaoMaoTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void executeTask() override
    {
        cout << "在海上冒险，找到 ONE PIECE 成为海贼王！" << endl;
    }
};

class SmokerTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void executeTask() override
    {
        cout << "为了正义, 先将草帽一伙一网打尽!!!" << endl;
    }
};

// 船的抽象类
class AbstractShip
{
public:
    AbstractShip(AbstractTeam* team) : m_team(team) {}
    void showTeam()
    {
        m_team->show();
        m_team->executeTask();
    }
    virtual string getName() = 0;
    virtual void feature() = 0;
    virtual ~AbstractShip() {}
protected:
    AbstractTeam* m_team = nullptr;
};

class Merry : public AbstractShip
{
public:
    using AbstractShip::AbstractShip;
    string getName() override
    {
        return string("前进·梅利号");
    }
    void feature() override
    {
        cout << getName()
            << " -- 船首为羊头, 在司法岛化身船精灵舍己救下了草帽一伙！" << endl;
    }
};

class HaiJunShip : public AbstractShip
{
public:
    using AbstractShip::AbstractShip;
    string getName() override
    {
        return string("无敌海军号");
    }
    void feature() override
    {
        cout << getName() << " -- 船底由海楼石建造, 可以穿过无风带的巨大炮舰!" << endl;
    }
};

int main()
{
    // 草帽海贼团
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

    // 斯摩格的船队
    SmokerTeam* team = new SmokerTeam("斯摩格的海军部队");
    Person* smoker = new Person("斯摩格", "中将", "冒烟果实能力者", "", "爱吃烟熏鸡肉");
    Person* dasiqi = new Person("达斯琪", "大佐", "一刀流", "", "近视");
    team->addMember(smoker);
    team->addMember(dasiqi);
    HaiJunShip* ship = new HaiJunShip(team);
    ship->feature();
    ship->showTeam();

    cout << "================= = 资源释放 ==================" << "\n";

    delete caomao;
    delete sunny;
    delete team;
    delete ship;

    return 0;
}
*/

// 组合模式（Composite Pattern）
/*
//组合模式是一种结构型设计模式，它将对象组合成树形结构来表示 “部分 - 整体” 的层次关系，
//使得客户端对单个对象（叶子节点）和组合对象（组合节点）的操作具有一致性。该模式适用于需要处理层次化数据结构的场景，如文件系统、组织架构、游戏单位编队等。

//结构组成
//抽象节点（Component）：定义叶子节点和组合节点的公共接口（如AbstractTeam）。
//叶子节点（Leaf）：没有子节点的基本单元，实现抽象节点的接口（如LeafTeam）。
//组合节点（Composite）：包含子节点的容器，实现抽象节点的接口并管理子节点（如ManagerTeam）。

//示例场景
//以《海贼王》中草帽海贼团的战斗编队为例，构建一个树形结构的团队组织：总团队下包含多个分团，每个分团下又包含若干番队，
//通过组合模式统一处理单个番队和整个团队的战斗逻辑。

#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

// 抽象节点
class AbstractTeam
{
public:
    AbstractTeam(string name) :m_name(name) {}
    // 设置父节点
    void setParent(AbstractTeam* node)
    {
        m_parent = node;
    }
    AbstractTeam* getParent()
    {
        return m_parent;
    }
    string getName()
    {
        return m_name;
    }
    virtual bool hasChild()
    {
        return false;
    }
    virtual void add(AbstractTeam* node) {}
    virtual void remove(AbstractTeam* node) {}
    virtual void fight() = 0;
    virtual void display() = 0;
    virtual ~AbstractTeam() {}
protected:
    string m_name;
    AbstractTeam* m_parent = nullptr;
};

// 叶子节点的小队
class LeafTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void fight() override
    {
        cout << m_parent->getName() + m_name + "与黑胡子的船员进行近距离肉搏战..." << endl;
    }
    void display() override
    {
        cout << "我是" << m_parent->getName() << "下属的" << m_name << endl;
    }
    ~LeafTeam()
    {
        cout << "我是" << m_parent->getName() << "下属的" << m_name
            << ", 战斗已经结束, 拜拜..." << endl;
    }
};

// 管理者节点
class ManagerTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void fight() override
    {
        cout << m_name + "和黑胡子的恶魔果实能力者战斗!!!" << endl;
    }
    void add(AbstractTeam* node) override
    {
        node->setParent(this);
        m_children.push_back(node);
    }
    void remove(AbstractTeam* node) override
    {
        node->setParent(nullptr);
        m_children.remove(node);
    }
    bool hasChild()
    {
        return true;
    }
    list<AbstractTeam*> getChildren()
    {
        return m_children;
    }
    void display()
    {
        string info = string();
        for (const auto item : m_children)
        {
            if (item == m_children.back())
            {
                info += item->getName();
            }
            else
            {
                // 优先级: + > +=
                info += item->getName() + ", ";
            }
        }
        cout << m_name + "的船队是【" << info << "】" << endl;
    }
    ~ManagerTeam()
    {
        cout << "我是【" << m_name << "】战斗结束, 拜拜..." << endl;
    }
private:
    list<AbstractTeam*> m_children;
};

// 内存释放
void gameover(AbstractTeam* root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root && root->hasChild())
    {
        ManagerTeam* team = dynamic_cast<ManagerTeam*>(root);
        list<AbstractTeam*> children = team->getChildren();
        for (const auto item : children)
        {
            gameover(item);
        }
    }
    delete root;
}

// 和黑胡子战斗
void fighting()
{
    vector<string> nameList = {
        "俊美海贼团", "巴托俱乐部", "八宝水军", "艾迪欧海贼团",
        "咚塔塔海贼团", "巨兵海贼团", "约塔玛利亚大船团"
    };
    // 根节点
    ManagerTeam* root = new ManagerTeam("草帽海贼团");
    for (int i = 0; i < nameList.size(); ++i)
    {
        ManagerTeam* child = new ManagerTeam(nameList.at(i));
        root->add(child);
        if (i == nameList.size() - 1)
        {
            // 给最后一个番队添加子船队
            for (int j = 0; j < 9; ++j)
            {
                LeafTeam* leaf = new LeafTeam("第" + to_string(j + 1) + "番队");
                child->add(leaf);
                leaf->fight();
                leaf->display();
            }
            child->fight();
            child->display();
        }
    }
    root->fight();
    root->display();

    cout << "====================================" << endl;
    gameover(root);
}

int main()
{
    fighting();
    return 0;
}
*/

// 装饰模式（Decorator Pattern）
/*
//装饰模式是一种结构型设计模式，它允许在不修改原有对象结构的前提下，动态地为对象添加新的功能。
//该模式通过创建一个包装对象（装饰器）来包裹原始对象，使客户端可以像使用原始对象一样使用装饰后的对象，同时获得额外的功能。

//结构组成
//抽象组件（Component）：定义对象的基本接口（如Soldier）。
//具体组件（Concrete Component）：实现抽象组件的具体对象（如Teach）。
//抽象装饰器（Decorator）：持有抽象组件的引用，并定义与抽象组件一致的接口（如DevilFruit）。
//具体装饰器（Concrete Decorator）：实现抽象装饰器，为组件添加新功能（如DarkFruit、QuakeFruit、PieFruit）。

//示例场景
//以《海贼王》中黑胡子的能力为例，通过装饰模式为黑胡子（原始组件）动态添加不同的恶魔果实能力（装饰器），
//每个果实能力都为其战斗方式增加新特性，且不改变黑胡子本身的战斗逻辑。

#include <iostream>
#include <string>
#include <memory>

using namespace std;

// 战士接口
class Soldier {
public:
    virtual ~Soldier() = default;
    virtual string getName() const = 0;
    virtual void fight() const = 0;
};

// 具体战士
class Teach : public Soldier {
private:
    string name;
public:
    explicit Teach(string n) : name(move(n)) {}

    string getName() const override { return name; }

    void fight() const override {
        cout << name << "依靠惊人的力量和高超的体术战斗..." << endl;
    }
};

// 恶魔果实装饰器基类
class DevilFruitDecorator : public Soldier {
protected:
    unique_ptr<Soldier> soldier;
public:
    explicit DevilFruitDecorator(unique_ptr<Soldier> s)
        : soldier(move(s)) {}

    string getName() const override { return soldier->getName(); }
};

// 暗暗果实
class DarkFruit : public DevilFruitDecorator {
public:
    using DevilFruitDecorator::DevilFruitDecorator;

    void fight() const override {
        soldier->fight();
        cout << getName()
             << "吃了暗暗果实, 可以拥有黑洞一样的无限吸引力..." << endl;
        warning();
    }

private:
    void warning() const {
        cout << getName()
             << "你要注意: 吃了暗暗果实, 身体元素化之后不能躲避攻击，会吸收所有伤害!" << endl;
    }
};

// 震震果实
class QuakeFruit : public DevilFruitDecorator {
public:
    using DevilFruitDecorator::DevilFruitDecorator;

    void fight() const override {
        soldier->fight();
        cout << getName()
             << "吃了震震果实, 可以在任意空间引发震动, 摧毁目标...!" << endl;
    }
};

// 大饼果实
class PieFruit : public DevilFruitDecorator {
public:
    using DevilFruitDecorator::DevilFruitDecorator;

    void fight() const override {
        soldier->fight();
        cout << getName()
             << "吃了大饼果实, 获得大饼铠甲...!" << endl;
        ability();
    }

private:
    void ability() const {
        cout << "最强辅助 -- 大饼果实可以将身边事物变成大饼, 帮助自己和队友回血..." << endl;
    }
};

int main() {
    // 创建黑胡子
    unique_ptr<Soldier> teach = make_unique<Teach>("马歇尔·D·蒂奇");

    // 动态添加恶魔果实能力（装饰器模式）
    teach = make_unique<DarkFruit>(move(teach));    // 暗暗果实
    teach = make_unique<QuakeFruit>(move(teach));   // 震震果实
    teach = make_unique<PieFruit>(move(teach));     // 大饼果实

    // 展示所有能力
    teach->fight();

    // 无需手动delete，智能指针自动管理内存
    return 0;
}
*/

// 外观模式（Facade Pattern）
/*
//外观模式是一种结构型设计模式，它为复杂系统提供一个简单的接口，隐藏系统内部的复杂实现，使客户端可以通过统一的接口访问系统。
//该模式通过封装子系统的交互逻辑，降低客户端与子系统的耦合度，提高代码的可维护性。

//结构组成
//外观类（Facade）：提供简单接口，封装子系统的复杂交互（如LionCannon）。
//子系统类（Subsystem Classes）：实现系统的具体功能，相互之间可能存在复杂交互（如CokeSystem、EnergySystem等）。

//示例场景
//以《海贼王》中桑尼号的 “狮吼炮” 发射系统为例：发射狮吼炮需要多个子系统协同工作（注入可乐、能量转换、目标锁定、开炮、稳定船身），
//外观模式将这些复杂步骤封装为简单的 “瞄准” 和 “开炮” 接口。

#include <iostream>
#include <string>

using namespace std;

// 乐可系统
class CokeSystem
{
public:
    void immitCoke()
    {
        cout << "狮吼炮原料<可乐>已经注入完毕..." << endl;
    }
};

// 能量转换系统
class EnergySystem
{
public:
    void energyConvert()
    {
        cout << "已经将所有的可乐转换为了能量..." << endl;
    }
};

// 目标锁定系统
class AimLockSystem
{
public:
    void aimLock()
    {
        cout << "已经瞄准并且锁定了目标..." << endl;
    }
};

// 加农炮发射系统
class Cannon
{
public:
    void cannonFire()
    {
        cout << "狮吼炮正在向目标开火..." << endl;
    }
};

// 风来炮稳定系统
class WindCannon
{
public:
    void windCannonFire()
    {
        cout << "发射风来炮抵消后坐力稳定船身..." << endl;
    }
};

// 上层接口
class LionCannon
{
public:
    LionCannon()
    {
        m_coke = new CokeSystem;
        m_energy = new EnergySystem;
        m_aimLock = new AimLockSystem;
        m_cannon = new Cannon;
        m_windCannon = new WindCannon;
    }
    ~LionCannon()
    {
        delete m_coke;
        delete m_energy;
        delete m_aimLock;
        delete m_cannon;
        delete m_windCannon;
    }
    // 瞄准并锁定目标
    void aimAndLock()
    {
        m_coke->immitCoke();
        m_energy->energyConvert();
        m_aimLock->aimLock();
    }
    // 开炮
    void fire()
    {
        m_cannon->cannonFire();
        m_windCannon->windCannonFire();
    }
private:
    CokeSystem* m_coke = nullptr;
    EnergySystem* m_energy = nullptr;
    AimLockSystem* m_aimLock = nullptr;
    Cannon* m_cannon = nullptr;
    WindCannon* m_windCannon = nullptr;
};

int main()
{
    // 发射狮吼炮
    LionCannon* lion = new LionCannon;
    lion->aimAndLock();
    lion->fire();
    delete lion;
    return 0;
}
*/

// 享元模式（Flyweight Pattern）
/*
//享元模式是一种结构型设计模式，它通过共享对象来减少内存占用和提高性能，适用于需要创建大量相似对象的场景。
//该模式将对象的状态分为内部状态（可共享的公共数据）和外部状态（每个对象独有的数据），通过共享内部状态来避免重复创建对象。

//结构组成
//抽象享元（Flyweight）：定义所有具体享元的公共接口（如FlyweightBody）。
//具体享元（Concrete Flyweight）：实现抽象享元接口，包含可共享的内部状态（如SharedBombBody）。
//唯一享元（Unique Flyweight）：无需共享的特殊享元（如UniqueBomb）。
//享元工厂（Flyweight Factory）：管理享元对象的创建和共享，避免重复实例化（如BombBodyFactory）。
//客户端（Client）：使用享元对象，维护对象的外部状态（如LaunchBomb）。

//示例场景
//以游戏中的 “炸弹发射” 系统为例：游戏中需要发射大量炸弹，这些炸弹的弹体外观（内部状态）可共享，而位置、速度（外部状态）各不相同。享元模式通过共享弹体对象，减少内存消耗。

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 享元基类
class FlyweightBody
{
public:
    FlyweightBody(string sprite) : m_sprite(sprite) {}
    virtual void move(int x, int y, int speed) = 0;
    virtual void draw(int x, int y) = 0;
    virtual ~FlyweightBody() {}
protected:
    string m_sprite;    // 精灵图片
    string m_color = string("black");     // 渲染颜色
};

// 炸弹弹体
class SharedBombBody : public FlyweightBody
{
public:
    using FlyweightBody::FlyweightBody;
    void move(int x, int y, int speed) override
    {
        cout << "炸弹以每小时" << speed << "速度飞到了("
            << x << ", " << y << ") 的位置..." << endl;
    }
    void draw(int x, int y) override
    {
        cout << "在 (" << x << ", " << y << ") 的位置重绘炸弹弹体..." << endl;
    }
};

// 唯一的炸弹彩蛋
class UniqueBomb : public FlyweightBody
{
public:
    using FlyweightBody::FlyweightBody;
    void move(int x, int y, int speed) override
    {
        // 此处省略对参数 x, y, speed的处理
        cout << "彩蛋在往指定位置移动, 准备爆炸发放奖励..." << endl;
    }
    void draw(int x, int y) override
    {
        cout << "在 (" << x << ", " << y << ") 的位置重绘彩蛋运动轨迹..." << endl;
    }
};

// 发射炮弹
class LaunchBomb
{
public:
    LaunchBomb(FlyweightBody* body) : m_bomb(body) {}
    int getX()
    {
        return m_x;
    }
    int getY()
    {
        return m_y;
    }
    void setSpeed(int speed)
    {
        m_speed = speed;
    }
    int getSpeed()
    {
        return m_speed;
    }
    void move(int x, int y)
    {
        m_x = x;
        m_y = y;
        m_bomb->move(m_x, m_y, m_speed);
        draw();
    }
    void draw()
    {
        m_bomb->draw(m_x, m_y);
    }

private:
    int m_x = 0;
    int m_y = 0;
    int m_speed = 100;
    FlyweightBody* m_bomb = nullptr;
};


// 享元工厂类
class BombBodyFactory
{
public:
    SharedBombBody* getSharedData(string name)
    {
        SharedBombBody* data = nullptr;
        // 遍历容器
        for (auto item : m_bodyMap)
        {
            if (item.first == name)
            {
                // 找到了
                data = item.second;
                cout << "正在复用 <" << name << ">..." << endl;
                break;
            }
        }
        if (data == nullptr)
        {
            data = new SharedBombBody(name);
            cout << "正在创建 <" << name << ">..." << endl;
            m_bodyMap.insert(make_pair(name, data));
        }
        return data;
    }
    ~BombBodyFactory()
    {
        for (auto item : m_bodyMap)
        {
            delete item.second;
        }
    }
private:
    map<string, SharedBombBody*> m_bodyMap;
};

int main()
{
    // 发射炮弹
    BombBodyFactory* factory = new BombBodyFactory;
    vector<LaunchBomb*> ballList;
    vector<string> namelist = { "撒旦-1", "撒旦-1", "撒旦-2", "撒旦-2", "撒旦-2", "撒旦-3" };
    for (auto name : namelist)
    {
        int x = 0, y = 0;
        LaunchBomb* ball = new LaunchBomb(factory->getSharedData(name));
        for (int i = 0; i < 3; ++i)
        {
            x += rand() % 100;
            y += rand() % 50;
            ball->move(x, y);
        }
        cout << "=========================" << endl;
        ballList.push_back(ball);
    }
    // 彩蛋
    UniqueBomb* unique = new UniqueBomb("大彩蛋");
    LaunchBomb* bomb = new LaunchBomb(unique);
    int x = 0, y = 0;
    for (int i = 0; i < 3; ++i)
    {
        x += rand() % 100;
        y += rand() % 50;
        bomb->move(x, y);
    }

    for (auto ball : ballList)
    {
        delete ball;
    }
    delete factory;
    delete unique;
    delete bomb;
    return 0;
}
*/

// 代理模式（Proxy Pattern）
/*
//代理模式是一种结构型设计模式，它通过创建一个代理对象来控制对原始对象的访问。
//代理对象与原始对象实现相同的接口，客户端通过代理对象间接访问原始对象，从而在不修改原始对象的情况下，添加额外的控制逻辑（如权限验证、缓存、日志记录等）。

//结构组成
//抽象接口（Subject）：定义代理和原始对象的公共接口（如Communication）。
//原始对象（Real Subject）：实现抽象接口的具体对象，完成实际业务逻辑（如Speaker）。
//代理对象（Proxy）：持有原始对象的引用，实现抽象接口，并在调用原始对象前后添加控制逻辑（如DenDenMushi）。

//示例场景
//以《海贼王》中的 “电话虫” 为例：电话虫作为代理，模仿通话者的语言和表情，在原始通话（Speaker）的基础上添加 “实时模仿” 的功能，客户端通过电话虫间接进行交流。

#include <iostream>
#include <string>

using namespace std;

// 抽象通信类
class Communication
{
public:
    virtual void communicate() = 0; // 通话
    virtual ~Communication() {}
};

// 讲话的人
class Speaker : public Communication
{
public:
    void communicate() override
    {
        cout << "开始说话..." << endl;
        cout << "通话时发生了一些列的表情变化..." << endl;
    }
};

// 电话虫
class DenDenMushi : public Communication
{
public:
    DenDenMushi()
    {
        m_isStart = true;
        m_speaker = new Speaker;
    }
    ~DenDenMushi()
    {
        if (m_speaker != nullptr)
        {
            delete m_speaker;
        }
    }
    // 判断是否已经开始通话了
    bool isStart()
    {
        return m_isStart;
    }
    void communicate() override
    {
        if (isStart())
        {
            // 得到通话者语言和表情信息, 并加以模仿
            cout << "电话虫开始实时模仿通话者的语言和表情..." << endl;
            m_speaker->communicate();
        }
    }
private:
    bool m_isStart = false;
    Speaker* m_speaker = nullptr;
};

int main()
{
    // 直接交流
    Communication* comm = new Speaker;
    comm->communicate();
    delete comm;
    cout << "===================================" << endl;
    // 使用电话虫
    comm = new DenDenMushi;
    comm->communicate();
    delete comm;

    return 0;
}
*/
#pragma endregion

#pragma region 行为模式
// 责任链模式（Chain of Responsibility Pattern）
/*
//责任链模式是一种行为型设计模式，它将处理请求的对象连成一条链，当请求发送时，链上的对象依次处理请求，直到有一个对象处理它为止。
//该模式避免了请求发送者和接收者之间的耦合，使多个对象都有机会处理请求，提高了系统的灵活性。

//结构组成
//抽象处理者（Handler）：定义处理请求的接口，包含设置下一个处理者的方法（如AbstractManager）。
//具体处理者（Concrete Handler）：实现抽象处理者接口，处理请求或传递给下一个处理者（如Manager、CEO、Boss）。
//客户端（Client）：发送请求到责任链（如DaCongMing）。

//示例场景
//以公司员工的请求处理为例：员工（大聪明）向公司提出请假、涨薪或辞职的请求，
//请求依次经过部门经理、CEO、老板的处理，每个管理者根据权限决定处理请求或传递给下一级。

#include <iostream>
using namespace std;

enum class RequestType :char { QingJia, ZhangXin, CiZhi };
// 抽象的任务节点类
class AbstractManager
{
public:
    void setNext(AbstractManager* manager)
    {
        m_next = manager;
    }
    virtual void handleRequest(RequestType type) = 0;
    virtual ~AbstractManager() {}
protected:
    AbstractManager* m_next = nullptr;
};

// 初级管理者
class Manager : public AbstractManager
{
public:
    void handleRequest(RequestType type)
    {
        switch (type)
        {
        case RequestType::QingJia:
            cout << "请假: 同意请假，好好休息~~~" << endl;
            break;
        case RequestType::ZhangXin:
            cout << "涨薪: 这个我得请示一下咱们CEO..." << " ====> ";
            m_next->handleRequest(type);
            break;
        case RequestType::CiZhi:
            cout << "辞职: 我给你向上级反应一下..." << " ====> ";
            m_next->handleRequest(type);
            break;
        default:
            break;
        }
    }
};

// CEO
class CEO : public AbstractManager
{
public:
    void handleRequest(RequestType type)
    {
        switch (type)
        {
        case RequestType::QingJia:
            cout << "请假: 同意请假, 下不为例..." << endl;
            break;
        case RequestType::ZhangXin:
            cout << "涨薪: 你工资不少了, 给你个购物券吧..." << endl;
            break;
        case RequestType::CiZhi:
            cout << "辞职: 这个我得问问咱们老板..." << " ====> ";
            m_next->handleRequest(type);
            break;
        default:
            break;
        }
    }
};

// 老板
class Boss : public AbstractManager
{
public:
    void handleRequest(RequestType type)
    {
        switch (type)
        {
        case RequestType::QingJia:
            cout << "请假: 只有工作才能实现人生价值，回去好好坚守岗位！！！" << endl;
            break;
        case RequestType::ZhangXin:
            cout << "涨薪: 钱财乃身外之物, 要视其如粪土!!!" << endl;
            break;
        case RequestType::CiZhi:
            cout << "辞职: 巴洛克工作社就是你的家, 这次把你留下, 下次别再提了!!!" << endl;
            break;
        default:
            break;
        }
    }
};

// 卑微的大聪明
class DaCongMing
{
public:
    void request(RequestType type, AbstractManager* manager)
    {
        manager->handleRequest(type);
    }
};

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
    cout << "========== 大聪明向顶头上司提要求 ==========" << endl;
    boy->request(RequestType::QingJia, manager);
    boy->request(RequestType::ZhangXin, manager);
    boy->request(RequestType::CiZhi, manager);
    cout << "========== 大聪明越级找CEO提要求 ==========" << endl;
    boy->request(RequestType::QingJia, ceo);
    boy->request(RequestType::ZhangXin, ceo);
    boy->request(RequestType::CiZhi, ceo);
    cout << "========== 大聪明直接找BOSS提要求 ==========" << endl;
    boy->request(RequestType::QingJia, boss);
    boy->request(RequestType::ZhangXin, boss);
    boy->request(RequestType::CiZhi, boss);

    delete boy;
    delete manager;
    delete ceo;
    delete boss;

    return 0;
}
*/

// 命令模式（Command Pattern）
/*
//命令模式是一种行为型设计模式，它将请求封装为对象，使客户端可以用不同的请求参数化对象，并且支持请求的排队、记录、撤销等操作。
//该模式通过解耦请求发送者和接收者，使系统更灵活地处理各种操作。

//结构组成
//接收者（Receiver）：执行请求的具体对象（如CookerZeff）。
//抽象命令（Command）：定义请求的接口，包含执行方法（如AbstractCommand）。
//具体命令（Concrete Command）：实现抽象命令，绑定接收者的具体操作（如DSXCommand、GBJDCommand）。
//调用者（Invoker）：发起请求，持有命令对象并执行其方法（如WaiterLuffy）。

//示例场景
//以餐厅点餐系统为例：顾客通过服务员（调用者）向厨师（接收者）下单，每个菜品对应一个命令对象（如地三鲜命令、宫保鸡丁命令），服务员负责管理订单（添加、取消、执行）。

#include <iostream>
#include <list>
#include <map>
using namespace std;

// 厨师哲普
class CookerZeff
{
public:
    void makeDSX()
    {
        cout << "开始烹饪地三鲜...";
    }
    void makeGBJD()
    {
        cout << "开始烹饪宫保鸡丁...";
    }
    void makeYXRS()
    {
        cout << "开始烹饪鱼香肉丝...";
    }
    void makeHSPG()
    {
        cout << "开始烹饪红烧排骨...";
    }
};

// 点餐的命令 - 抽象类
class AbstractCommand
{
public:
    AbstractCommand(CookerZeff* receiver) : m_cooker(receiver) {}
    virtual void excute() = 0;
    virtual string name() = 0;
    ~AbstractCommand() {}
protected:
    CookerZeff* m_cooker = nullptr;
};

// 地三鲜的命令
class DSXCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeDSX();
    }
    string name() override
    {
        return "地三鲜";
    }
};

// 宫保鸡丁的命令
class GBJDCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeGBJD();
    }
    string name() override
    {
        return "宫保鸡丁";
    }
};

// 鱼香肉丝的命令
class YXRSCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeYXRS();
    }
    string name() override
    {
        return "鱼香肉丝";
    }
};

// 红烧排骨的命令
class HSPGCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeHSPG();
    }
    string name() override
    {
        return "红烧排骨";
    }
};

// 服务器路飞 - 命令的调用者
class WaiterLuffy
{
public:
    // 下单
    void setOrder(int index, AbstractCommand* cmd)
    {
        cout << index << "号桌点了" << cmd->name() << endl;
        if (cmd->name() == "鱼香肉丝")
        {
            cout << "没有鱼了, 做不了鱼香肉丝, 点个别的菜吧..." << endl;
            return;
        }
        // 没找到该顾客
        if (m_cmdList.find(index) == m_cmdList.end())
        {
            list<AbstractCommand*> mylist{ cmd };
            m_cmdList.insert(make_pair(index, mylist));
        }
        else
        {
            m_cmdList[index].push_back(cmd);
        }
    }
    // 取消订单
    void cancelOrder(int index, AbstractCommand* cmd)
    {
        if (m_cmdList.find(index) != m_cmdList.end())
        {
            m_cmdList[index].remove(cmd);
            cout << index << "号桌, 撤销了" << cmd->name() << endl;
        }
    }
    // 结账
    void checkOut(int index)
    {
        cout << "第[" << index << "]号桌的顾客点的菜是: 【";
        for (const auto& item : m_cmdList[index])
        {
            cout << item->name();
            if (item != m_cmdList[index].back())
            {
                cout << ", ";
            }
        }
        cout << "】" << endl;
    }
    void notify(int index)
    {
        for (const auto& item : m_cmdList[index])
        {
            item->excute();
            cout << index << "号桌" << endl;
        }
    }
private:
    // 存储顾客的下单信息
    map<int, list<AbstractCommand*>> m_cmdList;
};

int main()
{
    CookerZeff* cooker = new CookerZeff;
    WaiterLuffy* luffy = new WaiterLuffy;

    YXRSCommand* yxrs = new YXRSCommand(cooker);
    GBJDCommand* gbjd = new GBJDCommand(cooker);
    DSXCommand* dsx = new DSXCommand(cooker);
    HSPGCommand* hspg = new HSPGCommand(cooker);

    cout << "=================== 开始点餐 ===================" << endl;
    luffy->setOrder(1, yxrs);
    luffy->setOrder(1, dsx);
    luffy->setOrder(1, gbjd);
    luffy->setOrder(1, hspg);
    luffy->setOrder(2, dsx);
    luffy->setOrder(2, gbjd);
    luffy->setOrder(2, hspg);
    cout << "=================== 撤销订单 ===================" << endl;
    luffy->cancelOrder(1, dsx);
    cout << "=================== 开始烹饪 ===================" << endl;
    luffy->notify(1);
    luffy->notify(2);
    cout << "=================== 结账 ===================" << endl;
    luffy->checkOut(1);
    luffy->checkOut(2);

    return 0;
}
*/

// 解释器模式（Interpreter Pattern）
/*
//解释器模式是一种行为型设计模式，它定义了一种语言的语法表示，并提供解释器来处理该语法。
//该模式将语法规则表示为类层次结构，每个语法规则对应一个表达式类，使语言的解释过程更加灵活和可扩展。

//结构组成
//抽象表达式（Abstract Expression）：定义解释操作的接口（如Expression）。
//终结符表达式（Terminal Expression）：实现与文法中的终结符相关的解释操作（如NumberExpression）。
//非终结符表达式（Non-terminal Expression）：实现文法中非终结符的解释操作（如AddExpression、SubtractExpression）。
//上下文（Context）：包含解释器需要的全局信息（示例中隐式使用）。

//示例场景
//以简单的算术表达式解释器为例：使用解释器模式解析并计算形如(3 + (5 - 2)) + 7的表达式。
//每个操作符（如+、-）和操作数（如3、5）都对应一个表达式类，通过组合这些类构建表达式树并求值。

#include <iostream>
#include <memory>

using namespace std;

// 抽象表达式接口
class Expression {
public:
    virtual ~Expression() = default;
    virtual int interpret() = 0;
};

// 终结符表达式：数字
class NumberExpression : public Expression {
    int value;
public:
    explicit NumberExpression(int v) : value(v) {}
    int interpret() override { return value; }
};

// 非终结符表达式：加法
class AddExpression : public Expression {
    unique_ptr<Expression> left;
    unique_ptr<Expression> right;
public:
    AddExpression(unique_ptr<Expression> l, unique_ptr<Expression> r)
        : left(move(l)), right(move(r)) {
    }

    int interpret() override {
        return left->interpret() + right->interpret();
    }
};

// 非终结符表达式：减法
class SubtractExpression : public Expression {
    unique_ptr<Expression> left;
    unique_ptr<Expression> right;
public:
    SubtractExpression(unique_ptr<Expression> l, unique_ptr<Expression> r)
        : left(move(l)), right(move(r)) {
    }

    int interpret() override {
        return left->interpret() - right->interpret();
    }
};

int main() {
    // 构建表达式树：(3 + (5 - 2)) + 7
    auto expr = make_unique<AddExpression>(
        make_unique<AddExpression>(
            make_unique<NumberExpression>(3),
            make_unique<SubtractExpression>(
                make_unique<NumberExpression>(5),
                make_unique<NumberExpression>(2)
            )
        ),
        make_unique<NumberExpression>(7)
    );

    cout << "Result: " << expr->interpret() << endl; // 输出：13
    return 0;
}
*/

// 迭代器模式（Iterator Pattern）
/*
//##迭代器模式的应用场景：需要将集合与它对应的遍历算法解耦。
//所以我们需要提供一种解决方案使其能够顺序访问一个集合对象中的各个元素，
//而又不暴露该集合底层的表现形式（列表、栈、树、图等），这种行为设计模式就叫迭代器模式。

//迭代器模式是一种行为型设计模式，它提供一种顺序访问集合对象中元素的方式，而不暴露集合的底层表示。
//该模式将集合的遍历逻辑与集合本身解耦，使不同的遍历算法可以独立变化，客户端无需关心集合的具体实现。

//结构组成
//抽象迭代器（Iterator）：定义遍历集合的接口（如first()、next()、isDone()）。
//具体迭代器（Concrete Iterator）：实现抽象迭代器接口，维护遍历状态（如ForwardIterator、ReverseIterator）。
//抽象集合（Aggregate）：定义创建迭代器的接口（如getIterator()）。
//具体集合（Concrete Aggregate）：实现抽象集合接口，返回具体迭代器（如MyList）。

//示例场景
//以《海贼王》中百兽海贼团的 “凌空六子” 及真打成员名单为例，使用双向链表存储成员列表，并通过迭代器实现正向和逆向遍历（如凯多检阅部下时的顺序访问）。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//##实际需求需放到MyList.h文件中
//#pragma once
//#include <string>
//using namespace std;
// 定义一个链表节点
struct Node
{
    Node(string n) : name(n) {}
    string name = string();
    Node* next = nullptr;
    Node* prev = nullptr;
};

class Iterator;
// 双向链表
class MyList
{
public:
    inline int getCount()
    {
        return m_count;
    }

    inline Node* head()
    {
        return m_head;
    }

    inline Node* tail()
    {
        return m_tail;
    }

    Node* insert(Node* item, string data);
    Node* pushFront(string data);
    Node* pushBack(string data);
    Iterator* getIterator(bool isReverse = false);

private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    int m_count = 0;
};

//##实际需求需放到Iterator.h文件中
// 抽象的迭代器类
class Iterator
{
public:
    Iterator(MyList* mylist) : m_list(mylist) {}
    Node* current()
    {
        return m_current;
    }
    virtual Node* first() = 0;
    virtual Node* next() = 0;
    virtual bool isDone() = 0;
    virtual ~Iterator() {}
protected:
    MyList* m_list = nullptr;
    Node* m_current = nullptr;
};

// 正向迭代器
class ForwardIterator : public Iterator
{
public:
    using Iterator::Iterator;
    Node* first() override
    {
        m_current = m_list->head();
        return m_current;
    }
    Node* next() override
    {
        m_current = m_current->next;
        return m_current;
    }
    bool isDone() override
    {
        return m_current == m_list->tail()->next;
    }
};

// 逆向迭代器
class ReverseIterator : public Iterator
{
public:
    using Iterator::Iterator;
    Node* first() override
    {
        m_current = m_list->tail();
        return m_current;
    }
    Node* next() override
    {
        m_current = m_current->prev;
        return m_current;
    }
    bool isDone() override
    {
        return m_current == m_list->head()->prev;
    }
};

//##实际需求需放到MyList.cpp文件中
//#include "MyList.h"
//#include "Iterator.h"
Node* MyList::insert(Node* item, string data)
{
    Node* node = nullptr;
    if (item == m_head)
    {
        node = pushFront(data);
    }
    else
    {
        node = new Node(data);
        node->next = item;
        node->prev = item->prev;
        // 重新连接
        item->prev->next = node;
        item->prev = node;
        m_count++;
    }
    return node;
}

Node* MyList::pushFront(string data)
{
    Node* node = new Node(data);
    // 空链表
    if (m_head == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        node->next = m_head;
        m_head->prev = node;
        m_head = node;
    }
    m_count++;
    return node;
}

Node* MyList::pushBack(string data)
{
    Node* node = new Node(data);
    // 空链表
    if (m_tail == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        m_tail->next = node;
        node->prev = m_tail;
        m_tail = node;
    }
    m_count++;
    return node;
}

Iterator* MyList::getIterator(bool isReverse)
{
    Iterator* iterator = nullptr;
    if (isReverse)
    {
        iterator = new ReverseIterator(this);
    }
    else
    {
        iterator = new ForwardIterator(this);
    }
    return iterator;
}

int main()
{
    vector<string> nameList{
        "烬", "奎因", "杰克", "福兹·弗", "X·德雷克",
        "黑色玛利亚", "笹木", "润媞", "佩吉万",
        "一美", "二牙", "三鬼", "四鬼", "五鬼",
        "六鬼", "七鬼", "八茶", "九忍","十鬼"
    };
    MyList mylist;
    for (int i = 0; i < nameList.size(); ++i)
    {
        mylist.pushBack(nameList.at(i));
    }
    // 遍历
    Iterator* it = mylist.getIterator(true);
    cout << "检阅开始, 凯多: 同志们辛苦啦~~~~~" << endl;
    for (auto begin = it->first(); !it->isDone(); it->next())
    {
        cout << "   " << it->current()->name << "say: 为老大服务!!! " << endl;
    }
    cout << endl;
    delete it;
    return 0;
}
*/

// 中介者模式（Mediator Pattern）
/*
//##中介者模式的应用场景：当一些对象和其他对象紧密耦合以致难以对其进行修改时；当组件因过于依赖其他组件而无法在不同应用中复用时；
//当为了能在不同情景下复用一些基本行为，导致需要被迫创建大量组件子类时，都可使用中介者模式。

//中介者模式是一种行为型设计模式，它通过引入一个中介者对象来封装一系列对象之间的交互，使这些对象不再直接相互引用，而是通过中介者进行通信。
//该模式降低了对象间的耦合度，使系统更易于维护和扩展。

//结构组成
//抽象中介者（Mediator）：定义中介者与同事类交互的接口（如MediatorOrg）。
//具体中介者（Concrete Mediator）：实现抽象中介者接口，协调同事类的交互（如WorldGovt、GeMingArmy）。
//抽象同事类（Colleague）：定义同事类与中介者交互的接口（如Country）。
//具体同事类（Concrete Colleague）：实现抽象同事类接口，通过中介者与其他同事类交互（如Alabasta、Dressrosa）。

//示例场景
//以《海贼王》中的国家外交为例：不同国家（阿拉巴斯坦、德雷斯罗萨等）通过中介机构（世界政府、革命军）进行消息传递。世界政府作为中介时，消息仅发送给指定国家；革命军作为中介时，消息广播给所有成员国家，体现不同中介者的交互策略。

#include <iostream>
#include <string>
#include <map>

using namespace std;

class MediatorOrg;
// 抽象国家类
class Country
{
public:
    Country(MediatorOrg* mediator) : m_mediator(mediator) {}
    // 发表声明
    virtual void declare(string msg, string country) = 0;
    virtual void setMessage(string msg) = 0;
    virtual string getName() = 0;
    virtual ~Country() {}
protected:
    MediatorOrg* m_mediator = nullptr;
};

// 抽象的中介机构
class MediatorOrg
{
public:
    void addMember(Country* country);
    virtual void declare(string msg, Country* country, string name = string()) = 0;
    virtual ~MediatorOrg() {}
protected:
    map<string, Country*> m_countryMap;
};

//##实际需求需放到Mediator.h文件中
// 世界政府
class Country;
class WorldGovt : public MediatorOrg
{
public:
    void declare(string msg, Country* country, string name = string()) override;
};

//##实际需求需放到Mediator.cpp文件中
//#include <iostream>
//#include "Mediator.h"
//#include "Country.h"
//using namespace std;
// 基类的成员添加函数
void MediatorOrg::addMember(Country* country)
{
    m_countryMap.insert(make_pair(country->getName(), country));
}

// 在子类中重写发表声明的函数
void WorldGovt::declare(string msg, Country* country, string name)
{
    if (m_countryMap.find(name) != m_countryMap.end())
    {
        string str = msg + "【来自: " + country->getName() + "】";
        m_countryMap[name]->setMessage(str);
    }
}

//##实际需求需放到Mediator.h文件中
// 革命军
class GeMingArmy : public MediatorOrg
{
public:
    void declare(string msg, Country* country, string name = string()) override;
};

//##实际需求需放到Mediator.cpp文件中
// 在子类中重写发表声明的函数
void GeMingArmy::declare(string msg, Country* country, string name)
{
    string str = msg + "【来自: " + country->getName() + "】";
    for (const auto& item : m_countryMap)
    {
        if (item.second == country)
        {
            continue;
        }
        item.second->setMessage(str);
    }
}

//#pragma once
//#include <string>
//#include <iostream>
//#include "Mediator.h"
//using namespace std;

// 阿拉巴斯坦
class Alabasta : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "阿拉巴斯坦得到的消息: " << msg << endl;
    }
    string getName() override
    {
        return "阿拉巴斯坦";
    }
};

// 德雷斯罗萨
class Dressrosa : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "德雷斯罗萨得到的消息: " << msg << endl;
    }
    string getName() override
    {
        return "德雷斯罗萨";
    }
};

// 露露西亚王国
class Lulusia : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "露露西亚得到的消息: " << msg << endl;
    }
    string getName() override
    {
        return "露露西亚";
    }
};

// 卡玛巴卡王国
class Kamabaka : public Country
{
public:
    using Country::Country;
    void declare(string msg, string country) override
    {
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "卡玛巴卡得到的消息: " << msg << endl;
    }
    string getName() override
    {
        return "卡玛巴卡";
    }
};

int main()
{
    // 世界政府
    WorldGovt* world = new WorldGovt;
    Alabasta* alaba = new Alabasta(world);
    Dressrosa* dresa = new Dressrosa(world);
    // 世界政府添加成员
    world->addMember(alaba);
    world->addMember(dresa);
    // 世界政府成员发声
    alaba->declare("德雷斯罗萨倒卖军火, 搞得我国连年打仗, 必须给个说法!!!", dresa->getName());
    dresa->declare("天龙人都和我多弗朗明哥做生意, 你算老几, 呸!!!", alaba->getName());
    cout << "======================================" << endl;
    // 革命军
    GeMingArmy* geming = new GeMingArmy;
    Lulusia* lulu = new Lulusia(geming);
    Kamabaka* kama = new Kamabaka(geming);
    geming->addMember(lulu);
    geming->addMember(kama);
    lulu->declare("我草, 我的国家被伊姆毁灭了!!!", lulu->getName());

    delete world;
    delete alaba;
    delete dresa;
    delete geming;
    delete lulu;
    delete kama;
    return 0;
}
*/

// 备忘录模式（Memento Pattern）
/*
//##备忘录模式的应用场景：当你需要创建对象状态快照来恢复其之前的状态时（比如游戏存档、文本编辑器）
//当直接访问对象的成员变量、获取器或设置器将导致封装被突破时（主要是为了保护数据的安全性，不允许篡改）

//备忘录模式是一种行为型设计模式，它允许在不暴露对象内部状态的前提下，捕获并保存对象的状态，以便后续将对象恢复到保存的状态。
//该模式通过分离状态的保存和管理，实现了对象状态的快照机制，常用于需要回滚操作或保存历史状态的场景。

//结构组成
//原发器（Originator）：创建并恢复状态的对象（如JiaoPenJi）。
//备忘录（Memento）：保存原发器的状态，确保状态不被外部修改（如History）。
//管理者（Caretaker）：存储和管理备忘录，不直接操作备忘录的内容（如Recorder）。

//示例场景
//以 "脚盆鸡（日本）承认历史罪行" 为例：原发器对象（脚盆鸡）有多个不承认历史罪行的状态，通过备忘录记录这些状态，
//当被 "兔子（中国）" 教训后，被迫依次承认这些罪行，实现状态的恢复和展示。

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// 历史备忘录类
class History
{
public:
    History(string msg) : m_msg(msg) {}
    string getHistory()
    {
        return m_msg;
    }
private:
    string m_msg;
};

// 鬼子
class JiaoPenJi
{
public:
    void setState(string msg)
    {
        m_msg = msg;
    }

    string getState()
    {
        return m_msg;
    }

    void beiDaddyDa()
    {
        cout << "脚盆鸡被兔子狠狠地揍了又揍, 终于承认了它们之前不承认的这些罪行: " << endl;
    }

    History* saveHistory()
    {
        return new History(m_msg);
    }
    void getStateFromHistory(History* history)
    {
        m_msg = history->getHistory();
    }
private:
    string m_msg;
};

// 记录者
class Recorder
{
public:
    void addHistory(int index, History* history)
    {
        m_history.insert(make_pair(index, history));
    }
    History* getHistory(int index)
    {
        if (m_history.find(index) != m_history.end())
        {
            return m_history[index];
        }
        return nullptr;
    }
private:
    map<int, History*> m_history;
};

int main()
{
    vector<string> msg{
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
    for (int i = 0, size = msg.size(); i < size; ++i)
    {
        jiaopen->setState(msg.at(i));
        recorder->addHistory(i, jiaopen->saveHistory());
    }
    jiaopen->beiDaddyDa();
    for (int i = 0, size = msg.size(); i < size; ++i)
    {
        jiaopen->getStateFromHistory(recorder->getHistory(i));
        cout << "  -- " << jiaopen->getState() << endl;
    }
    return 0;
}
*/

// 观察者模式（Observer Pattern）
/*
//##观察者模式的应用场景：当一个对象的状态发生变化，并且需要改变其它对象的时候；或者当应用中一些对象必须观察其它对象的时候可以使用观察者模式。

//观察者模式是一种行为型设计模式，它定义了对象之间的一对多依赖关系，当一个对象的状态发生变化时，所有依赖它的对象都会收到通知并自动更新。
//该模式通过解耦发布者（被观察对象）和订阅者（观察者），使系统更易于维护和扩展。

//结构组成
//抽象主题（Subject）：定义添加、删除和通知观察者的接口（如NewsAgency）。
//具体主题（Concrete Subject）：实现抽象主题接口，维护观察者列表并在状态变化时通知观察者（如Morgans、Gossip）。
//抽象观察者（Observer）：定义接收通知的接口（如Observer）。
//具体观察者（Concrete Observer）：实现抽象观察者接口，处理接收到的通知（如Dragon、Shanks）。

//示例场景
//以《海贼王》中的新闻传播为例：摩根斯新闻社和八卦新闻社作为主题，革命军龙、红发香克斯、巴托洛米奥作为观察者订阅不同的新闻社。当新闻社发布新闻时，订阅者会收到相应通知。

#include <iostream>
#include <string>
#include <list>
using namespace std;

//在头文件中只是对 Observer 类进行了声明定义了这种类型的指针变量，在源文件中需要调用 Observer 类提供的 API，
//所以必须要包含这个类的头文件。这么处理的目的是为了避免两个相互关联的类他们的头文件相互包含。

//##实际需求需放到NewsAgency.h文件中
// 声明订阅者类, 只是做了声明, 并没有包含这个类的头文件
class Observer;
// 新闻社
class NewsAgency
{
public:
    void attach(Observer* ob);
    void deatch(Observer* ob);
    virtual void notify(string msg) = 0;
    virtual ~NewsAgency() {};
protected:
    // 订阅者列表
    list<Observer*> m_list;
};

//##实际需求需放到Observer.h文件中
//#pragma once
//#include <string>
//#include <iostream>
//#include "NewsAgency.h"
//using namespace std;
// 抽象的订阅者类
class Observer
{
public:
    Observer(string name, NewsAgency* news) :m_name(name), m_news(news)
    {
        m_news->attach(this);
    }
    void unsubscribe()
    {
        m_news->deatch(this);
    }
    virtual void update(string msg) = 0;
    virtual ~Observer() {}
protected:
    string m_name;
    NewsAgency* m_news;
};

//##实际需求需放到NewsAgency.cpp文件中
//#include "NewsAgency.h"
//#include "Observer.h"	// 在源文件中包含该头文件
//#include <iostream>
void NewsAgency::attach(Observer* ob)
{
    m_list.push_back(ob);
}

void NewsAgency::deatch(Observer* ob)
{
    m_list.remove(ob);
}

//##实际需求需放到NewsAgency.h文件中
// 摩根斯的新闻社
class Morgans : public NewsAgency
{
public:
    void notify(string msg) override;
};

//##实际需求需放到NewsAgency.cpp文件中
void Morgans::notify(string msg)
{
    cout << "摩根斯新闻社报纸的订阅者一共有<" << m_list.size() << ">人" << endl;
    for (const auto& item : m_list)
    {
        item->update(msg);	// 订阅者类的定义在下面
    }
}

//##实际需求需放到NewsAgency.h文件中
// 八卦新闻
class Gossip : public NewsAgency
{
public:
    void notify(string msg) override;
};

//##实际需求需放到NewsAgency.cpp文件中
void Gossip::notify(string msg)
{
    cout << "八卦新闻社报纸的订阅者一共有<" << m_list.size() << ">人" << endl;
    for (const auto& item : m_list)
    {
        item->update(msg);
    }
}

class Dragon : public Observer
{
public:
    using Observer::Observer;
    void update(string msg) override
    {
        cout << "@@@路飞的老爸革命军龙收到消息: " << msg << endl;
    }
};

class Shanks : public Observer
{
public:
    using Observer::Observer;
    void update(string msg) override
    {
        cout << "@@@路飞的引路人红发香克斯收到消息: " << msg << endl;
    }
};

class Bartolomeo : public Observer
{
public:
    using Observer::Observer;
    void update(string msg) override
    {
        cout << "@@@路飞的头号粉丝巴托洛米奥收到消息: " << msg << endl;
    }
};

int main()
{
    Morgans* ms = new Morgans;
    Gossip* gossip = new Gossip;
    Dragon* dragon = new Dragon("蒙奇·D·龙", ms);
    Shanks* shanks = new Shanks("香克斯", ms);
    Bartolomeo* barto = new Bartolomeo("巴托洛米奥", gossip);
    ms->notify("蒙奇·D·路飞成为新世界的新的四皇之一, 赏金30亿贝里!!!");
    cout << "======================================" << endl;
    gossip->notify("女帝汉库克想要嫁给路飞, 给路飞生猴子, 哈哈哈...");

    delete ms;
    delete gossip;
    delete dragon;
    delete shanks;
    delete barto;

    return 0;
}
*/

// 策略模式（Strategy Pattern）
/*
//##策略模式的应用场景：策略模式中的若干个策略对象相互之间是完全独立的， 它们不知道其他对象的存在。当我们想使用对象中各种不同的算法变体，
//并希望能够在运行的时候切换这些算法时，可以选择使用策略模式来处理这个问题。 

//策略模式是一种行为型设计模式，它定义了一系列算法，并将每个算法封装起来，使它们可以相互替换。
//该模式让算法的变化独立于使用算法的客户端，适用于需要在运行时动态切换算法的场景。

//结构组成
//抽象策略（Strategy）：定义所有支持算法的公共接口（如AbstractStrategy）。
//具体策略（Concrete Strategy）：实现抽象策略接口的具体算法（如YiDang、ErDang等）。
//上下文（Context）：持有一个策略对象的引用，负责选择和使用策略（如Luffy）。

//示例场景
//以《海贼王》中路飞的战斗模式为例：路飞根据敌人的强度（简单、普通、困难等）动态切换战斗策略（一档到五档），每种策略对应不同的攻击方式，体现了算法的动态切换。

#include <iostream>
#include <string>

using namespace std;

// 抽象的策略类
class AbstractStrategy
{
public:
    virtual void fight(bool isfar = false) = 0;
    virtual ~AbstractStrategy() {}
};

// 一档
class YiDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 现在使用的是一档: ";
        if (isfar)
        {
            cout << "橡胶机关枪" << endl;
        }
        else
        {
            cout << "橡胶·攻城炮" << endl;
        }
    }
};

// 二挡
class ErDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 切换成二挡: ";
        if (isfar)
        {
            cout << "橡胶Jet火箭" << endl;
        }
        else
        {
            cout << "橡胶Jet·铳乱打" << endl;
        }
    }
};

// 三挡
class SanDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 切换成三挡: ";
        if (isfar)
        {
            cout << "橡胶巨人回旋弹" << endl;
        }
        else
        {
            cout << "橡胶巨人战斧" << endl;
        }
    }
};

// 四挡
class SiDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 切换成四挡: ";
        if (isfar)
        {
            cout << "橡胶狮子火箭炮" << endl;
        }
        else
        {
            cout << "橡胶犀牛榴弹炮" << endl;
        }
    }
};

// 五档
class WuDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 切换成五挡: 变成尼卡形态可以把物体变成橡胶, 并任意改变物体的形态对其进行攻击!!!" << endl;
    }
};

// 难度级别
enum class Level :char { Easy, Normal, Hard, Experts, Professional };

// 路飞
class Luffy
{
public:
    void fight(Level level, bool isfar = false)
    {
        if (m_strategy)
        {
            delete m_strategy;
            m_strategy = nullptr;
        }
        switch (level)
        {
        case Level::Easy:
            m_strategy = new YiDang;
            break;
        case Level::Normal:
            m_strategy = new ErDang;
            break;
        case Level::Hard:
            m_strategy = new SanDang;
            break;
        case Level::Experts:
            m_strategy = new SiDang;
            break;
        case Level::Professional:
            m_strategy = new WuDang;
            break;
        default:
            break;
        }
        m_strategy->fight(isfar);
    }
    ~Luffy()
    {
        delete m_strategy;
    }
private:
    AbstractStrategy* m_strategy = nullptr;
};

int main()
{
    Luffy* luffy = new Luffy;
    cout << "--- 在香波地群岛遇到了海军士兵: " << endl;
    luffy->fight(Level::Easy);
    cout << "--- 在魔谷镇遇到了贝拉米: " << endl;
    luffy->fight(Level::Normal);
    cout << "--- 在司法岛遇到了罗布·路奇: " << endl;
    luffy->fight(Level::Hard);
    cout << "--- 在德雷斯罗萨遇到了多弗朗明哥: " << endl;
    luffy->fight(Level::Experts);
    cout << "--- 在鬼岛遇到了凯多: " << endl;
    luffy->fight(Level::Professional);

    delete luffy;
    return 0;
}
*/

// 状态模式（State Pattern）
/*
//##状态模式的应用场景：如果对象需要根据当前自身状态进行不同的行为，
//同时状态的数量非常多且与状态相关的代码会频繁变更或者类对象在改变自身行为时需要使用大量的条件语句时，可使用状态模式。

//状态模式是一种行为型设计模式，它允许对象在内部状态改变时改变其行为，使对象看起来像是修改了自身的类。
//该模式将状态封装为独立的类，通过状态之间的转换来改变对象的行为，避免使用大量条件判断语句。

//结构组成
//抽象状态（State）：定义状态相关的接口或抽象类（如AbstractState）。
//具体状态（Concrete State）：实现抽象状态接口，定义特定状态下的行为（如ForenoonState、NoonState等）。
//上下文（Context）：持有当前状态的引用，根据状态调用相应行为（如Sanji）。

//示例场景
//以《海贼王》中桑吉的一天为例：桑吉根据时间（上午、中午、下午、晚上）切换不同的状态，每个状态对应不同的行为（准备早餐、做午饭、制作甜点、做晚饭等），体现了状态变化时行为的自动切换。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//##实际需求需放到State.h文件中
// 抽象状态
class Sanji;
class AbstractState
{
public:
    virtual void working(Sanji* sanji) = 0;
    virtual ~AbstractState() {}
};

// 上午状态
class ForenoonState : public AbstractState
{
public:
    void working(Sanji* sanji) override;
};

// 中午状态
class NoonState : public AbstractState
{
public:
    void working(Sanji* sanji) override;
};

// 下午状态
class AfternoonState : public AbstractState
{
public:
    void working(Sanji* sanji) override;
};

// 晚上状态
class EveningState : public AbstractState
{
public:
    void working(Sanji* sanji) override;
};

//##实际需求需放到Sanji.h文件中
//#pragma once
//#include "State.h"
class AbstractState;
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

//##实际需求需放到State.cpp文件中
//#include <iostream>
//#include "State.h"
//#include "Sanji.h"
//using namespace std;
void ForenoonState::working(Sanji* sanji)
{
    int time = sanji->getClock();
    if (time < 8)
    {
        cout << "当前时间<" << time << ">点, 准备早餐, 布鲁克得多喝点牛奶..." << endl;
    }
    else if (time > 8 && time < 11)
    {
        cout << "当前时间<" << time << ">点, 去船头钓鱼, 储备食材..." << endl;
    }
    else
    {
        sanji->setState(new NoonState);
        sanji->working();
    }
}

void NoonState::working(Sanji* sanji)
{
    int time = sanji->getClock();
    if (time < 13)
    {
        cout << "当前时间<" << time << ">点, 去厨房做午饭, 给路飞多做点肉..." << endl;
    }
    else
    {
        sanji->setState(new AfternoonState);
        sanji->working();
    }
}

void AfternoonState::working(Sanji* sanji)
{
    int time = sanji->getClock();
    if (time < 15)
    {
        cout << "当前时间<" << time << ">点, 准备下午茶, 给罗宾和娜美制作爱心甜点..." << endl;
    }
    else if (time > 15 && time < 18)
    {
        cout << "当前时间<" << time << ">点, 和乔巴去船尾钓鱼, 储备食材..." << endl;
    }
    else
    {
        sanji->setState(new EveningState);
        sanji->working();
    }
}

void EveningState::working(Sanji* sanji)
{
    int time = sanji->getClock();
    if (time < 19)
    {
        cout << "当前时间<" << time << ">点, 去厨房做晚饭, 让索隆多喝点汤..." << endl;
    }
    else
    {
        cout << "当前时间<" << time << ">点, 今天过得很高兴, 累了睡觉了..." << endl;
    }
}

int main()
{
    Sanji* sanji = new Sanji;
    // 时间点
    vector<int> data{ 7, 10, 12, 14, 16, 18, 22 };
    for (const auto& item : data)
    {
        sanji->setClock(item);
        sanji->working();
    }
    delete sanji;

    return 0;
}
*/

// 模板方法模式（Template Method Pattern）
/*
//##模板方法模式的应用场景：我们在实现子类的时候，如果发现不变的行为和可变的行为混合在了一起，
//导致不变的行为在多个子类中重复出现，此时就可以使用模板方法模式把不变的行为搬到基类中，
//去除子类里边的重复代码，来体现它的优势，模板方法模式就是提供了一个很好的代码复用平台。
//它可以将一些复杂的流程的实现步骤封装在一系列基本方法中，在抽象父类中提供一个称之为模板方法的方法来定义这些基本方法的执行次序。

//模板方法模式是一种行为型设计模式，它在抽象类中定义了一个算法的骨架，将一些步骤延迟到子类中实现。
//该模式允许子类在不改变算法结构的情况下，重新定义算法中的某些步骤，从而实现代码复用和行为定制。

//结构组成

//抽象类（Abstract Class）：
//定义模板方法（如getProperty()），包含算法的骨架。
//声明抽象方法（如weapon()、appearance()），由子类实现。
//提供具体方法（如canFlying()、isAuto()），作为默认实现或钩子方法。

//具体子类（Concrete Subclass）：
//实现抽象类中的抽象方法，定制算法的特定步骤。
//可选地覆盖钩子方法（如selfHealing()），修改默认行为。

//示例场景
//以《海贼王》中贝加庞克制造的机器人为例：
//和平主义者（Pacifist）：基础机器人，能发射镭射光，无飞行能力。
//炽天使（Seraphim）：升级版机器人，继承和平主义者能力，增加飞行、自愈和更强的战斗能力。
//通过模板方法模式，将机器人属性的展示流程（getProperty()）固定在抽象类中，子类只需实现特定属性即可。

#include <iostream>
#include <string>

using namespace std;

// 抽象机器人类
class AbstractRobot
{
public:
    // 武器
    virtual void weapon() = 0;
    // 外观
    virtual void appearance() = 0;
    // 战斗能力
    virtual void fightAbility() = 0;
    // 名字
    virtual string getName() = 0;
    // 自愈能力
    virtual void selfHealing() {};
    // 是否能飞
    virtual bool canFlying()
    {
        return false;
    }
    // 是否是自动控制
    virtual bool isAuto()
    {
        return true;
    }
    // 得到机器人属性
    virtual void getProperty()
    {
        cout << "贝加庞克制造的" << getName() << "有以下属性: " << endl;
        if (canFlying())
        {
            cout << "有飞行能力!" << endl;
        }
        else
        {
            cout << "没有飞行能力!" << endl;
        }
        if (isAuto())
        {
            cout << "可以自动控制, 完全体机器人!" << endl;
        }
        else
        {
            cout << "不能自动控制, 半自动机器人!" << endl;
        }
        weapon();
        appearance();
        fightAbility();
        selfHealing();
    }
};

// 和平主义者
class Pacifist : public AbstractRobot
{
public:
    // 武器
    void weapon() override
    {
        cout << "可以发射镭射光..." << endl;
    }
    // 外观
    void appearance() override
    {
        cout << "外部和巴索罗米·熊一样, 体型庞大，拥有呈半圆形的耳朵，内部似乎金属。" << endl;
    }
    // 能力
    void fightAbility() override
    {
        cout << "结实抗揍, 可以通过手部或者嘴部发射镭射激光, 可以融化钢铁!!!" << endl;
    }
    string getName() override
    {
        return "和平主义者";
    }
};

// 炽天使
class Seraphim : public AbstractRobot
{
public:
    // 武器
    void weapon() override
    {
        cout << "可以发射镭射激光, 鹰眼外形的炽天使携带者一把巨剑, 可以斩断一切!!!" << endl;
    }
    // 外观
    void appearance() override
    {
        cout << "外观和七武海小时候的外形一样, 并且拥有一对和烬一样的翅膀!!!" << endl;
    }
    // 能力
    void fightAbility() override
    {
        cout << "不仅可以发射镭射激光, 还拥有七武海的能力, 牛逼plus, 无敌了!!!!" << endl;
    }
    // 自愈能力
    void selfHealing() override
    {
        cout << "非常厚实抗揍, 并且拥有非常强的自愈能力, 开挂了!!!" << endl;
    }
    // 是否能飞
    bool canFlying() override
    {
        return true;
    }
    string getName() override
    {
        return "炽天使";
    }
};

int main()
{
    AbstractRobot* robot = nullptr;
    robot = new Pacifist;
    robot->getProperty();
    delete robot;
    cout << "====================================" << endl;
    robot = new Seraphim;
    robot->getProperty();
    delete robot;
    return 0;
}
*/

// 访问者模式（Visitor Pattern）
/*
//##访问者模式的应用场景：访问者模式适用于数据结构比较稳定的系统，
//对于上面的例子而言就是指草帽团成员：只有男性和女性（不会再出现其它性别）。在剥离出的行为状态类中针对男性和女性提供了相对应的 doing 方法。
//这种模式的优势就是可以方便的给对象添加新的状态和处理动作，也就是添加新的 AbstractAction 子类（算法类），
//在需要的时候让这个子类去访问某个成员对象，访问者模式的最大优势就是使算法的增加变得更加容易维护。
//如果不按照性别进行划分，草帽团一共9个成员就需要在行为状态类中给每个成员提供一个 doing 方法，当草帽团又添加了新的成员，
//状态类中也需要给新成员再添加一个对应的 doing 方法，这就破坏了设计模式的开放 – 封闭原则。
//访问者不是常用的设计模式， 因为它不仅复杂， 应用范围也比较狭窄。

//访问者模式是一种行为型设计模式，它允许将作用于某种数据结构中各元素的操作分离出来，形成独立的类，
//使系统在不修改数据结构的前提下，新增对元素的操作。该模式通过 “双分派” 机制，将数据结构与操作解耦，适用于数据结构稳定但操作频繁变化的场景。

//结构组成
//抽象访问者（Visitor）：定义访问元素的接口（如AbstractAction）。
//具体访问者（Concrete Visitor）：实现抽象访问者接口，定义对不同元素的操作（如Anger、Horror）。
//抽象元素（Element）：定义接受访问者的接口（如AbstractMember）。
//具体元素（Concrete Element）：实现抽象元素接口，接收访问者并调用其操作（如MaleMember、FemaleMember）。
//对象结构（Object Structure）：管理元素集合，支持遍历和接受访问者（如CaoMaoTeam）。

//示例场景
//以《海贼王》中草帽海贼团成员面对敌人时的反应为例：
//成员分为男性（路飞、索隆等）和女性（娜美、罗宾）。
//访问者表示成员的状态（愤怒、恐惧），不同性别成员在相同状态下的反应不同（男性战斗，女性求助）。

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

//##实际需求需放到Visitor.h文件中
// 类声明
class MaleMember;
class FemaleMember;
// 抽象的动作类
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

//##实际需求需放到Member.h文件中
//#pragma once
//#include <iostream>
//#include "Visitor.h"
//using namespace std;
// 抽象的成员类
class AbstractMember
{
public:
    AbstractMember(string name) :m_name(name) {}
    string getName()
    {
        return m_name;
    }
    // 接受状态对象的访问
    virtual void accept(AbstractAction* action) = 0;
    virtual ~AbstractMember() {}
protected:
    string m_name;
};

// 男性成员
class MaleMember : public AbstractMember
{
public:
    AbstractMember::AbstractMember;
    void accept(AbstractAction* action) override
    {
        action->maleDoing(this);
    }
};

// 女性成员
class FemaleMember : public AbstractMember
{
public:
    AbstractMember::AbstractMember;
    void accept(AbstractAction* action) override
    {
        action->femalDoing(this);
    }
};
//##accept() 函数是一个双分派操作，它得到执行的操作不仅取决于传入的状态类的具体状态，还取决于它访问的人的类别。


//##实际需求需放到Visitor.cpp文件中
//#include <iostream>
//#include "Visitor.h"
//#include "Member.h"
//#include <list>
//#include <vector>
using namespace std;

void Anger::maleDoing(MaleMember* male)
{
    cout << "我是草帽海贼团的" << male->getName() << endl;
    fight();
}

void Anger::femalDoing(FemaleMember* female)
{
    cout << "我是草帽海贼团的" << female->getName() << endl;
    warning();
}

void Anger::warning()
{
    cout << "大家块逃，我快顶不住了, 不要管我!!!" << endl;
}

void Anger::fight()
{
    cout << "只要还活着就得跟这家伙血战到底!!!" << endl;
}

void Horror::maleDoing(MaleMember* male)
{
    cout << "我是草帽海贼团的" << male->getName() << endl;
    thinking();
}

void Horror::femalDoing(FemaleMember* female)
{
    cout << "我是草帽海贼团的" << female->getName() << endl;
    help();
}

void Horror::help()
{
    cout << "这个大熊太厉害, 太可怕了, 快救救我。。。" << endl;
}

void Horror::thinking()
{
    cout << "得辅助同伴们一块攻击这个家伙, 不然根本打不过呀!!!" << endl;
}

//##实际需求需放到Visitor.cpp文件中
// 草帽团
class CaoMaoTeam
{
public:
    CaoMaoTeam()
    {
        m_actions.push_back(new Anger);
        m_actions.push_back(new Horror);
    }
    void add(AbstractMember* member)
    {
        m_members.push_back(member);
    }
    void remove(AbstractMember* member)
    {
        m_members.remove(member);
    }
    void display()
    {
        for (const auto& item : m_members)
        {
            int index = rand() % 2;
            item->accept(m_actions[index]);
        }
    }
    ~CaoMaoTeam()
    {
        for (const auto& item : m_members)
        {
            delete item;
        }
        for (const auto& item : m_actions)
        {
            delete item;
        }
    }
private:
    list<AbstractMember*> m_members;
    vector<AbstractAction*> m_actions;
};

int main()
{
    srand(time(NULL));
    vector<string> names{
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
*/
#pragma endregion
#pragma endregion