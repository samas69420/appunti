#include<iostream>
#define LOG(x) std::cout << x << std::endl
#define COLSIZE 4

// iterator: the thing that iterates upon the elements of the iterable class
class Iterator
{
public:
    Iterator(int* ptr):ptr(ptr){}
    int* operator++() {
        ptr++;
        return ptr;
    }
    bool operator!=(Iterator other){
        if(other.ptr != ptr){ return true;}
        else{return false;}
    };
    int operator*(){return *ptr;}
private:
    int* ptr;
};

// iterable class: it has something to iterate on and can create iterators
// that will iterate on it according to their own rules
class Collection 
{
public: 
    Collection(){};
    Iterator begin(){ return Iterator(col);}
    Iterator end(){ return Iterator(col+COLSIZE);}
private:
    int col[COLSIZE] = {1,2,3,4}; // elements to iterate on
};

int main()
{
    Collection c;
    // short form
    for(int val : c)
        LOG(val);
    //// extended form
    //for(Iterator it = c.begin(); 
    //    it != c.end();
    //    ++it)
    //{
    //    LOG(*it);
    //}
}
