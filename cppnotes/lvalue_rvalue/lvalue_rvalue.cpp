#include<iostream>
#define LOG(x) std::cout << x << std::endl

void lfun(int& x) // int& is a lval reference and can't be used to get rval ref
{
    LOG("lval received: "<< x);
}
void rfun(int&& x) // int&& is a rval reference and can't be used to get lval ref
{
    LOG("rval received: "<< x);
}

struct Dummy{int x;};

int& GetValue()
{
    static int value = 777;
    return value;
}

int main()
{
    int x = 69; // x: l; 69 = r;
    lfun(x); 
    //rfun(x); // error
    rfun(420); 
    //lfun(420); // error 
    rfun(Dummy{666}.x); 
    //lfun(Dummy{666}.x); // error
    GetValue() = -3; // kind of the same as *value = -3
    LOG(GetValue());
}
