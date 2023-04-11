#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Dummy
{
public:
    int* data;
    Dummy(){
        data = new int(420);
        LOG("dummy def constr - heap allocation");
    }
    Dummy(int a){
        data = new int(a);
        LOG("dummy int constr - heap allocation");
    }
    Dummy(Dummy&& other){
        LOG("dummy rval constr");
        data = other.data;
        other.data = nullptr;
    }
    ~Dummy(){
        LOG("dummy destroyed");
        delete data;
    }

    Dummy& operator=(Dummy&& other){
        if(&other!=this){
            LOG("moving data and freeing memory containing "<<*data);
            delete data; // to avoid memory leak
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};

int main()
{
    Dummy d; 
    Dummy d2(69); 
    d = (Dummy&&)d2; // moving data from d2 into d
    LOG(*d.data);
}
