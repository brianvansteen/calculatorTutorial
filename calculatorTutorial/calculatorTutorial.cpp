// calculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Calculator.h"
#include <vector>
#define Hello_World std::cout<<"I am from a macro!"<<std::endl;

using namespace std;

class Vehicle // definition
{
public:
    Vehicle(); // constructor
    float getSpeed(); // functions
    void accelerate(); // functions
    virtual void beepHorn() = 0; // functions
    float speed; // data; variable
    virtual void decelerate() = 0; // pure virtual function; class becomes abstract that cannot be directly used; can inherite from it and implement the pure virtual function

private:
    // float speed; // data; variable
};

class Train : public Vehicle // definition inherite from the vehicle class; all properties and functions from vehicle; cannot access private
{
public:
    Train(); // constructor
    void beepHorn(); // to have train beepHorn instead of vehicle beepHorn
    void decelerate();
};

class Car : public Vehicle // definition inherite from the vehicle class; all properties and functions from vehicle; cannot access private
{
public:
    Car(); // constructor
    void beepHorn(); // to have train beepHorn instead of vehicle beepHorn
    void decelerate();
};

Car::Car() // constructor
{

}

void Car::beepHorn()
{
    if (getSpeed() < 0.5f)
    {
        std::cout << getSpeed() << ": pippip says the car" << std::endl;
    }
    else
    {
        std::cout << getSpeed() << ": BWOOOOAR says the car!" << std::endl;
    }
}

Train::Train() // constructor
{

}

void Train::beepHorn()
{
    if (getSpeed() < 0.5f)
    {
        std::cout << getSpeed() << ": bip bip says the train" << std::endl;
    }
    else
    {
        std::cout << getSpeed() << ": BOOP BIIP says the train!" << std::endl;
    }
}

void Train::decelerate()
{
    speed -= 0.5f;
}

void Car::decelerate()
{
    speed -= 0.5f;
}

Vehicle::Vehicle() : speed(0.0f) // constructor; initialization of speed
{

}

float Vehicle::getSpeed()
{
    return speed;
}

void Vehicle::accelerate()
{
    speed += 0.5f;
}

//void Vehicle::decelerate()
//{
//    speed -= 0.5f;
//}

//void Vehicle::beepHorn()
//{
//    std::cout << "meep meep" << std::endl;
//}

int main()
{

    int a, b, d;
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';

    Hello_World;

    //Vehicle v;
    //v.beepHorn();

    Train t;
    t.beepHorn();
    t.accelerate();
    t.beepHorn();
    t.decelerate();
    t.beepHorn();
    std::cout << "Standalone" << std::endl << std::endl;

    std::vector<Vehicle*> vehicles;

    vehicles.push_back(new Car()); // child class elements
    vehicles.push_back(new Train());

    for (Vehicle* v : vehicles)
    {
        std::cout << "Vectors" << std::endl;
        v->beepHorn();
        v->getSpeed();
        v->accelerate();
        v->beepHorn();
        v->decelerate();
        v->beepHorn();
        std::cout << std::endl;
    }

    Vehicle* v1 = new Car(); // child class
    Vehicle* v2 = new Train(); // child class

    std::cout << "New calls:" << std::endl;
    v1->beepHorn();
    v2->beepHorn();
    v1->accelerate();
    v1->beepHorn();

    //cout << "Hello World!\n";
    //cout << "Calculator Console Application" << endl << endl;
    //cout << "Please enter the operation. Format: a+b | a-b | a*b | a/b | a%b "
    //    << endl;
    
    /* cout << "Please enter two numbers:\n";
    cin >> a >> b; */

    /* cout << "What is your name?\n"
    getline(cin,strName) */

    Calculator c;
    while (true)
    {
        cin >> x >> oper >> y;
        if (oper == '/' && y == 0)
        {
            cout << "Division by 0 exception" << endl;
            continue;
        }
        else
        {
            result = c.Calculate(x, oper, y);
        }

        cout << "Result is: " << result << endl;

        /* d = a + b;
        cout << "The sum is: " << d << endl; */
    }

    return 0;
}
