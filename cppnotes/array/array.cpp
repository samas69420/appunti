#include<iostream>
#define LOG(x) std::cout << x << std::endl

template<typename T,size_t S>
class Array
{
public:
    constexpr size_t Size() const {return S;}

    // using T without & wont work for stuff that changes the output (like data[i] = 69)
    T& operator[](size_t index){ return m_Data[index];}

    // first const is for when calling this method on "const T" objects instead of T
    // second const is to ensure that those object will actually stay in the same state
    const T& operator[](size_t index) const { return m_Data[index];}

    T* Data() {return m_Data;}
    const T* Data() const {return m_Data;}
private:
    T m_Data[S];
};

int main()
{
    int size = 5;
    //Array<int,5> data;

    Array<std::string,3> data;
    data[1] = "ayy";

    const auto& cdata = data; // reference to data but readonly because of "const"

    static_assert(data.Size() != 0);

    for(size_t i = 0 ; i<data.Size() ; i++){
        LOG(cdata[i]);
    }
}
