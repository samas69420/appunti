#include<iostream>
#define LOG(x) std::cout << x << std::endl

#include<memory>

class Dummy{
public:
    Dummy(){LOG("constructor");}
    ~Dummy(){LOG("destructor");}
};

int main()
{
    std::unique_ptr<Dummy>uptr(new Dummy());
    std::unique_ptr<Dummy>uptr_m=std::make_unique<Dummy>();//make_unique for safety
    //ptr_make=ptr; // error because pointers must be unique

    std::shared_ptr<Dummy>sptr(new Dummy()); // inefficient because of control block
    std::shared_ptr<Dummy>sptr_m=std::make_shared<Dummy>();//make_shared for efficiency
    sptr = sptr_m;
    std::shared_ptr<Dummy>sptr2(sptr); // sptr and sptr2 shares same data

    std::weak_ptr<Dummy> wptr(sptr);
}
