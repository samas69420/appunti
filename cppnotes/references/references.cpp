#include<iostream>
#define LOG(x) std::cout << x << std::endl

void ptr_fun(int* ptr)
{
    LOG(*ptr);
}

void ref_fun(int& ref) //same code of ptr fun but more readable and less memory use
{
    LOG(ref);
}

int main()
{
    int var = 69;
    int& ref = var;
    ref = 10;
    ptr_fun(&var);
    ref_fun(ref);
}
