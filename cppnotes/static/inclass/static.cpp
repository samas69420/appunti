#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Vehicle 
{   
private:
    int private_x;
public:
    static int static_x; // must be defined somewhere as individual variable
    static void static_fun(int x)
    {
        LOG("static fun, received: " << x);
        //LOG(private_x); // gives error cuz static method has no instance
    }
};
int Vehicle::static_x; // without this linker error


int main()
{
    //int Vehicle::static_x; // error cuz apparently static members cant be in main

    Vehicle v1;
    v1.static_x = 2;

    Vehicle v2;
    v2.static_x = 4;

    Vehicle::static_x = 69;
    LOG(v1.static_x);
    LOG(v2.static_x);
    LOG(Vehicle::static_x);

    v1.static_fun(420);
    Vehicle::static_fun(0);
}
