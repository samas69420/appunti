#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Dummy{
public:
    Dummy(){LOG("dummy");}
    Dummy(int x){LOG("dummy int");}
};

class Entity{   
    Dummy z;
public:
    int x, y;
    Entity(){ // constructor (when object is created)
        LOG("entity's constructor called");
    }
    Entity(int x) // constructor overloading (when having more constructors)
        : x(69), y(420), z(666) // initializer list to set default values
    {
        LOG("entity's constructor called");
        this->x = x;
    }
    Entity(int x, int y){ // broken constructor
        LOG("entity's constructor called");
        z = Dummy(-3); // if no init list 2 calls will be made to dummy's constructor
        this->x = x;
    }
    Entity(Dummy d) 
        : x(1), y(2), z(d) // there is no Dummy(Dummy) constructor so d is copied in z
    {
        LOG("entity's dummy constructor called");
    }
    ~Entity(){ // destructor (when go out of scope)
        LOG("entity's destructor called");
    }
};

class EntityNoDefault{
    EntityNoDefault() = delete; // disable default constructor
};

int main()
{
    //Entity e(777); // nice constructor
    //Entity e2(420,69); // broken constructor
    ////EntityNoDefault e_n_d; // error because cant find any constructor
    Entity e3(Dummy(49)); // costructor that will not call Dummy() for entity
}
