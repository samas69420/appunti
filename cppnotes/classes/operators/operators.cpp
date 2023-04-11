#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Entity{
public:
    int x;
    Entity(int x):x(x){}

    Entity operator+(Entity& e){ // giving sense to "e1+e2", otherwise error
        return Entity(x+e.x);
    }
};

std::ostream& operator<<(std::ostream& stream, Entity& e){
    stream << e.x;
    return stream;
}

int main(){
    Entity e1(69);
    std::cout << e1 << std::endl ;
    Entity e2(420);
    Entity e3 = e1 + e2;
    LOG(e3.x);
}
