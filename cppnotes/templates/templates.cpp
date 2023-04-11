#include<iostream>
#define LOG(x) std::cout << x << std::endl

template<typename T>
void Print(T x){
    LOG(x);
}

int main()
{
    int x = 69;
    float y = 420.0f;
    const char* a = "bruh\0";

    Print(x); // template arg(s) gets guessed by compiler
    Print<float>(y); // template arg(s) is specified
    Print(a);
}
