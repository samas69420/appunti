#include<iostream>
#define LOG(x) std::cout << x << std::endl

int main()
{
    // without auto 
    //int a = 69;
    //int b = a;

    // with auto (type gets guessed) 
    auto a = 69;
    auto b = a;

    LOG(b);
}
