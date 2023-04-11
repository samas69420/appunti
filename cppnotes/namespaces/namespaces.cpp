#include<iostream>
#define LOG(x) std::cout << x << std::endl

namespace fiz{
    namespace buz{
        void print(int x){LOG("fiz buz " << x);}
    }
}

namespace bruh{
    void print(int x){LOG("bruh " << x);}
}

class Entity{
public:
    Entity(int x):x(x){};
    int x;
    const static int sx = 666;
    static void print(){LOG("class");}
};

int main()
{
    int x = 69;

    namespace ns = fiz::buz;
    ns::print(x);

    using namespace bruh;
    print(x);

    using fiz::buz::print;
    print(x);

    Entity e(420);
    LOG(Entity::sx); // class as namespace for static things
    Entity::print(); // class as namespace for static things
}
