#include<cstring>
#include<iostream>
#define LOG(x) std::cout << x << std::endl

class String{
private:
    char* m_data; uint32_t m_size;
public:
    String(const char* string){
        LOG("created");
        m_size = strlen(string); m_data = new char[m_size];
        memcpy(m_data, string, m_size);
    }
    String(const String& other){
        LOG("copied");
        m_size = other.m_size; m_data = new char[m_size];
        memcpy(m_data, other.m_data, m_size);
    }
    String(String&& other){
        LOG("moved");
        m_size = other.m_size; m_data = other.m_data; // "steal" other's attributes
        other.m_size = 0; other.m_data = nullptr;     // invalidate other's attributes
    }
    ~String(){
        LOG("destroyed");
        delete m_data;
    }
    void Print(){
        LOG(m_data);
    }
};

class Entity{
private:
    String m_name;
public:
    Entity(const String& name)
        : m_name(name) // String copy constructor called here from init list
            {LOG("Entity const String& constr");}
    Entity(String&& name) // String&& for rval parameters
        : m_name((String&&)name)             // without "String&&", const String& constructor is used, why?
            {LOG("Entity String&& constr");} // because inside init list "name" is cosidered as a lvalue (https://stackoverflow.com/questions/7166133/rvalue-reference-usage-within-initialization-lists)
    void Printname(){m_name.Print();}
};

int main(){
    Entity e(String("bruh")); // String("bruh") is rval here 
    e.Printname();
}
