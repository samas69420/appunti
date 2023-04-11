#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Entity{
private:
    int x;
public:
    Entity(int x):x(x){}
    
    friend int friendly_fun(Entity* e); // let friendly_fun use private members
};

int friendly_fun(Entity* e){
    return e->x;
}

int main(){
    Entity e(69);
    LOG(friendly_fun(&e));
}
