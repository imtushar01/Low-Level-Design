#include<iostream>
#include<string>

using namespace std;

class Car{
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void breaks() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {}
};

class sportsCar : public Car  {
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    sportsCar(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with roar!" << endl;
    }

    void shiftGear(int gear) {
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is Off, cannot shift gear" << endl;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Gear shifted to " << currentGear <<  endl;
    }

    void accelerate() {
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is Off, cannot accelerate" << endl;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << endl;
    }

    void breaks() {
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Breaking! Speed is now = " << currentSpeed << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned Off" << endl;
    }

};

int main() {

    Car* myCar = new sportsCar("Ford", "Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->breaks();
    myCar->shiftGear(1);
    myCar->stopEngine();

    delete myCar;

    return 0;
}