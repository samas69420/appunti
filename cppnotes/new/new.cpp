#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Entity{
public:
    int x;
    Entity(){LOG("default constructor called");}
    Entity(int x):x(x){LOG("constructor called");}
    ~Entity(){LOG("destructor called");}
};

int main()
{
    Entity e_on_stak;
    Entity* e_on_heap = new Entity(666);

    int* var_on_heap = new int(420);

    int* ptr = (int*) malloc(sizeof(int));
    int* placed_manually = new(ptr) int(69);

    Entity* e_array_on_heap = new Entity[5]; // cant use other constructors here

    LOG("----------");

    delete e_on_heap;
    delete var_on_heap;

    //delete e_array_on_heap; // error : segfault
    delete[] e_array_on_heap; 

    //delete placed_manually; undefined behaviour

    typedef int myint; // this is for using ...->~myint() syntax, otherwise error (https://stackoverflow.com/questions/456310/destructors-of-builtin-types-int-char-etc)
    placed_manually->~myint(); // this should be the standard way even tho in this case it does only a print
    free(ptr); 

    return 0;
}
