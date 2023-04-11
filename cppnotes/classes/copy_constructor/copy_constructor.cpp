#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Entity{
public:
    int x;
    Entity(int x):x(x){LOG("int constructor");}
    Entity(const Entity& other){ // only raw memcpy by default
        LOG("copy constructor");
    }

};

int main(){
    Entity e(69);
    Entity e_copy = e; // copy constructor called here by e_copy
    LOG(e.x);
    LOG(e_copy.x);
}
