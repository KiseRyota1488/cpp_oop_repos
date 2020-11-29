#include <iostream>
using namespace std;



class Cat
{
private:
    string name;
    int age = NULL;
public:
    Cat(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    Cat()
    {

    }

    void PrintInfo()
    {
        cout << name << " " << age;
    }



};



int main()
{
    Cat barsik;
    barsik.PrintInfo();



}