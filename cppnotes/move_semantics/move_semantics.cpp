#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Dummy
{
public:
    int* data;
    Dummy(){
        LOG("dummy def constr - heap allocation");
        data = new int(420);
    }
    Dummy(int a){
        LOG("dummy int constr - heap allocation");
        data = new int(a);
    }
    Dummy(Dummy&& other){
        LOG("dummy rval constr");
        data = other.data;
        other.data = nullptr;
    }
    ~Dummy(){
        LOG("dummy destroyed");
        delete data;
    }
};

class Entity{
public:
    Dummy dummy;
    Entity(){}
    Entity(Dummy&& x)
        : dummy((Dummy&&)x){LOG("entity from rval costr");} // call to Dummy&& costructor here
    ~Entity(){LOG("entity destroyed");}
};

int main()
{
    // goal is to allocate memory just once and then only fuck around with pointers

    Dummy d(69); 
    //Entity e((Dummy&&)d); // this will steal data from d
    Entity e(std::move(d)); // std::move like recasting with (Dummy&&)
    //Entity e(69); // using temporary dummy  

    LOG(*e.dummy.data); // 69
    //LOG(d.data); // 0
}
