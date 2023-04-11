#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Entity
{   
    int x_priv;
public:
    int x_pub;
};
               //   _____ access specifier
               //  |
class PubChild : public Entity
{
public:
    PubChild(){
        x_pub=69;    // this stays public
        //x_priv=69; // privacy error (only public things can be used)
    }
};

class PrivChild : private Entity
{
public:
    PrivChild(){
        x_pub=420; // this becomes private
        //x_priv=69; // privacy error (only public things can be used)
    }
};

int main()
{
    PubChild puc;
    PrivChild prc;
    LOG(puc.x_pub); 

    //LOG(prc.x_pub); //error
    //LOG(puc.x_priv);//error
    //LOG(prc.x_pub); //error
}
