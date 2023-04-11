#include<iostream>
#define LOG(x) std::cout << x << std::endl

void fun(int x){
    LOG("fun");
    LOG(x);
}

int main()
{
    void(*fun_ptr)(int) = fun;
    fun_ptr(69);
}
