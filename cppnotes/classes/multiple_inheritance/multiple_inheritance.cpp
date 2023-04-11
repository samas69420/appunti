#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Entity
{   
public:
    void print_entity(){LOG("entity");}
};


class Entity2
{   
public:
    void print_entity2(){LOG("entity2");}
};

class Child : public Entity, public Entity2{}; // entity and entity2 are both parents

int main()
{
    Child c;
    c.print_entity();
    c.print_entity2();
}
