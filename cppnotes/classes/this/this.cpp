#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Entity{
public:
    int x;

    //Entity(int y)
    //{
    //    x = y; // works fine
    //}

    Entity(int x)
    {
        //x = x; // doesnt work as expected
        this->x = x;
    }
};

int main(){
    Entity e(69);
    LOG(e.x);
}
