#include<iostream>
#define LOG(x) std::cout << x << std::endl

class Vehicle // like struct but private by default
{   
    int x;
public:
    int speed;
    // methods
    void log_speed(){
        LOG(speed << " sivolaa");
    }
    void log_x(){
        LOG(x);
    }
};


struct Vehicle_s // like class but public by default
{   
    int speed;
    // methods
    void log_speed(){
        LOG(speed << " struct");
    }
    void log_x(){
        LOG(x);
    }
private:
    int x;
};

int main()
{
    Vehicle_s car_s;
    car_s.speed = 69;
    car_s.log_speed();
    Vehicle car;
    car.speed = 130;
    car.log_speed();
    car.log_x();

    //car.x = 69;   // visibility error
    //car_s.x = 69; //
}
