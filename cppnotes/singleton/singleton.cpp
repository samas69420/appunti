#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Singleton
{
private:
    Singleton(){}
    Singleton(const Singleton&) = delete; // deleting copy constr. to disable copying
    static Singleton unique_instance;
public:
    static void s_fun(){ LOG("singleton function"); }
    static Singleton& get(){ return unique_instance; }
};

Singleton Singleton::unique_instance;


class Singleton2
{
private:
    Singleton2(){}
public:
    static void s_fun(){ LOG("singleton2 function"); }
    static Singleton2& get(){ 
            static Singleton2 u_inst{};
            return u_inst;
        }
};

int main()
{
    //Singleton s = Singleton::get(); // error because copy constructor is deleted
    Singleton::get().s_fun();
    Singleton2::get().s_fun();
    LOG(sizeof(Singleton)); // 1 
}
