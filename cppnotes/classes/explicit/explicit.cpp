#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Entity
{   
    int x;
public:
    Entity(int x){ // can be called by only its arg (implicit conversion)
        LOG("constructor int called");
    };
    explicit Entity(void* ptr){ // explicit disables conversion from its arg
        LOG("constructor ptr called");
    };
};

int main()
{
    void* p = NULL;
    Entity int_without_conversion(69);
    Entity int_with_conversion = 420;
    //Entity ptr_with_conversion = p; // error
    Entity ptr_without_conversion(p);
}
