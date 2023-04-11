#include<iostream>
#define LOG(x) std::cout << x << std::endl

int main()
{
    int var = 69;
    int* ptr = NULL; 
    ptr = &var;
    *ptr = 420;
    LOG(*ptr);
}
