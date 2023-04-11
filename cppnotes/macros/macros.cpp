#include<iostream>

#define DEBUG

#ifdef DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

int main()
{
    LOG(69);
}
