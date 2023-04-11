#include<iostream>
#define LOG(x) std::cout << x << std::endl

void apply_function(int& input, int(*function)(int)){
    input = function(input);
}

int main()
{
    int x = 69;
    int y = 420;
                    //          ___ lambda (used to define the function f(x)=x+1)
                    //         |
    apply_function(x, [](int x){return x+1;});
    LOG(x); 

    // to use captures std library and its types must be used apparently
    //apply_function(x, (int(*)(int))[y](int x){return y+1;});
    //LOG(x);         // |
    //                // |__ "captures" used to let the lamba use local variable y
}
