#include <iostream>
#include <list>
using namespace std;

void PRINT_DEV(string msg)
{
    bool is_print = true;
    if (is_print)
    {

    }
}

class DessertAddon {
private:
    string name;
public:
    DessertAddon(string name)
        :name(name)
    {

    }
};

class Dessert // Wojtek
{
private:
    string type;
    string size;
    string type_of_box;
    string category;
    double price;
    list <DessertAddon> AddonsList;

public:
    Dessert()
    {

    }
};

class Cake : public Dessert {
private:
    string cakeName;
public:
    Cake(string cakeName)
        :cakeName(cakeName)
    {

    }
};

class DessertsMachine // Dawid
{
private:
    list <Cake> CakeList;
    string machineName;
public:
    DessertsMachine(string machineName)
        :machineName(machineName)
    {

    }

    void addToList(Cake newCake)
    {
        this->CakeList.push_back(newCake);
    }

    void frontEndCore()
    {
        // zakodowaæ obs³uge cmd
    }
};

void machineSetup()
{
    DessertsMachine machine1("coffeeMaker");
    machine1.frontEndCore();
    Cake cake1("applePie");

    machine1.addToList(cake1);
}

int main() {
    machineSetup();
}

//TODO:
/*
1. front-end core
2. ogólna klasa deser i pochone tej klasy
3.
*/