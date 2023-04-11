#include<iostream>
#define LOG(x) std::cout << x << std::endl

int fun(){
    static int x; // basically a global variable that only "fun" can use
    return x++;
}

int main()
{
    LOG(fun()); // 0
    LOG(fun()); // 1
    LOG(fun()); // 2
}
