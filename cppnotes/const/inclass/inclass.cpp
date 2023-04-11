class Entity
{
public:
    int attribute;
    mutable int mut_attribute; // can be modified also by const method

    void method(){
        attribute = 69;
    }
    void method2() const { // can't modify "non mutable" attributes
        //attribute = 69; // error
        mut_attribute = 69;
    }
};

void fun(const Entity* e){
    //e->method(); // error because "method" doesnt promise to not modify the object
    e->method2();
}
