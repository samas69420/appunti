#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Interface{
public:
    virtual void pure_virt() = 0; // pure virtual function: no default impl,
                                  //                        MUST be implemented in child
};

class Entity{
public:
    virtual void print(){
        LOG("entity");
    }
};

class Child : public Entity, public Interface{   
public:
    void print(){
        LOG("child");
    }
    void pure_virt(){} // without this i get error
};

int main()
{
    Child c;
    Entity* e = &c;
    e->print();
}
