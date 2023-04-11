#include<iostream>
#define LOG(x) std::cout << x << std::endl

int main()
{
    // const like a promise
    const int a = 10; // making promise
    int* ptr;
    ptr =(int*) &a;
    *ptr = 69; // breaking promise (without errors or consequences apparently)
    LOG(a); // 10
    
    // const with pointers
    int var = 420;
    const int* ptr_2 = &var; // can reassign the pointer but can't change value
    //*ptr_2 = 666; // error
    ptr_2 = NULL; 
    int* const ptr_3 = &var; // can't reassign the pointer but can change value
    *ptr_3 = 666; 
    //ptr_3 = ptr_2; // error
    const int* const ptr_4 = &var; // can't reassign the pointer nor change value
    //*ptr_4 = 666; // error
    //ptr_4 = ptr_2; // error
}
