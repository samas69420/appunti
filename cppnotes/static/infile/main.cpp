#include<iostream>
#define LOG(x) std::cout << x << std::endl

//int s_var = 420; //s_var will be 420 for all translation units

static int s_var = 420; // s_var will exist and be 420 only in this translation unit

//extern int s_var; // use the one defined in static.cpp if not static
//                  // if it is static linking error

int main()
{
    LOG(s_var);
}
