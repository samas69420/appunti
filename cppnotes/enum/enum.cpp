#include<iostream>
#define LOG(x) std::cout << x << std::endl

// without enum
// int A = 69;
// int B = 70;
// int C = 71;

//with enum
enum Example: int
{
    A=69, B, C // A=69, B=70, C=71
};

int main()
{
    Example e = C;
    LOG(e);
}
