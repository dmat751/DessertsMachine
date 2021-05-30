#include <iostream>
#include <list>
#include <vector>
#include "Source.cpp"
using namespace std;

typedef int VectorIndex;
void PRINT_DEV(string msg)
{
    bool is_print = true;
    if (is_print)
    {

    }
}

//--- start Recipt section ------
class ReciptItem
{
private:
    double price;
    string name;
public:
    ReciptItem(double price, string name)
        :price(price), name(name)
    {

    }
    double getPrice()
    {
        return this->price;
    }
    string getName()
    {
        return this->name;
    }
};

class Receipt
{
private:
    vector <ReciptItem> reciptItemList;
public:
    Receipt()
    {

    }
    void addItemToReceipt(ReciptItem newReceiptItem)
    {
        reciptItemList.push_back(newReceiptItem);
    }
    void addReceiptToEachOther(Receipt& receiptToAdd)
    {
        int itemAmount = receiptToAdd.reciptItemList.size();
        for(int i = 0; i < itemAmount; i++)
        {
            this->addItemToReceipt(receiptToAdd.reciptItemList.at(i));
        }
    }
    void generateRecipt()
    {
        cout << "\n\n\n====paragon======\n";
        for (int i = 0; i < this->reciptItemList.size(); i++)
        {
            cout << "nazwa produktu: " << this->reciptItemList.at(i).getName() << " cena: " << this->reciptItemList.at(i).getPrice() << "\n";
        }
        cout << "koniec paragonu";
    }
    
};
//--- end Recipt section ------

//--- start DessertAddon section ------
class DessertAddon {
private:
    string name;
    double price;
public:
    DessertAddon(string name, double price)
        :name(name), price(price)
    {

    }
    string getAddonName()
    {
        return this->name;
    }
    double getAddonPrice()
    {
        return this->price;
    }
};

class IceCreamCupType : public DessertAddon
{
private:
    int maxScoops;
public:
    IceCreamCupType(string name, double price, int maxScoops)
        :maxScoops(maxScoops), DessertAddon(name, price)
    {}
    int getMaxScoops()
    {
        return this->maxScoops;
    }
};
//--- end DessertAddon section ------

//--- start Dessert section ------
class Dessert
{
private:
    string name;
    double price;

public:
    Dessert(string name, double price)
        :name(name), price(price)
    {

    }
    string getName()
    {
        return this->name;
    }
    double getPrice()
    {
        return this->price;
    }
};

class Cake : public Dessert {
private:
public:
    Cake(string name, double price)
        :Dessert(name, price)
    {

    }
};

class Coffee : public Dessert {
private:
public:
    Coffee(string name, double price)
        :Dessert(name, price)
    {

    }
};

class IceCreamCategory
{
private:
    string name;
    int ID;
    static int IDGenrator;
public:
    IceCreamCategory() {}
    IceCreamCategory(string name)
        :name(name)
    {
        this->ID = IDGenrator;
        IDGenrator++;
    }
};
int IceCreamCategory::IDGenrator = 0;

class IceCream : public Dessert {
private:
    static vector <IceCreamCupType> iceCreamCupTypeList;
    static vector <IceCreamCategory> avaiableCategoryList;
public:

    IceCream(string name, double price)
        :Dessert(name, price)
    {

    }
    static void addNewCupType(IceCreamCupType newType)
    {
        iceCreamCupTypeList.push_back(newType);
    }
    static int getMaxScoopsAmountFromCupList(int itemIndex)
    {
        return iceCreamCupTypeList.at(itemIndex).getMaxScoops();
    }
    static void printAvaiableCupList()
    {
        for (int i = 0; i < iceCreamCupTypeList.size(); i++)
        {
            string nazwa = iceCreamCupTypeList.at(i).getAddonName();
            double cena = iceCreamCupTypeList.at(i).getAddonPrice();
            int maxScoops = iceCreamCupTypeList.at(i).getMaxScoops();
            cout << (i + 1) << " - " << nazwa << " cena: " << cena << " max galek: " << maxScoops << "\n";
        }
    }
};
vector <IceCreamCupType> IceCream::iceCreamCupTypeList;

class IceCreamControler
{
private:
    vector <IceCream> iceCreamList;

    //-------------------
  
    int iceCreamTasteSelect()
    {

        int iceCreamSelect;

        for (int i = 0; i < this->iceCreamList.size(); i++)
        {

            cout << i + 1 << " - " << this->iceCreamList.at(i).getName() << "\n";
        }
        cout << "podaj liczbe: ";
        cin >> iceCreamSelect;
        iceCreamSelect--;
        return iceCreamSelect;
    }

    vector <VectorIndex> scoopsSelectMenu(int scoopsAmount)
    {
        vector <VectorIndex> selectedScoopsIndexes;
        for (int i = 0; i < scoopsAmount; i++)
        {
            cout << "wybierz smak: " << i + 1 << "\n";
            selectedScoopsIndexes.push_back(iceCreamTasteSelect());
        }
        return selectedScoopsIndexes;
    }

    int cupTypeSelect()
    {
        IceCream::printAvaiableCupList();
        cout << "podaj numer: ";
        int select;
        cin >> select;
        select--;
        return select;
    }
    //-------------------
public:
    IceCreamControler()
    {

    }
    void addIceCreamToList(IceCream newiceCream)
    {
        this->iceCreamList.push_back(newiceCream);
    }

    IceCream getElementFormIceCreamList(int index)
    {
        return this->iceCreamList.at(index);
    }
    Receipt menuControler()
    {
        Receipt iceCreamReceipt;
        cout << "wybrales typ: lody\n";
        // -- cup type select --

        int selectedCupIndex = this->cupTypeSelect();
        int maxAmountofScoopsPerCup = IceCream::getMaxScoopsAmountFromCupList(selectedCupIndex);

        // -- scoops amounts select --
        int inputedscoopsAmount;
        bool inputedScoopsAmountIsError = true;
        do
        {
            cout << "ile galek lodow chcesz?\n";
            cin >> inputedscoopsAmount;
            if (inputedscoopsAmount <= maxAmountofScoopsPerCup)
            {
                inputedScoopsAmountIsError = false;
            }
            else
            {
                cout << "podano zla ilosc galek lodow\n";
            }
        } while (inputedScoopsAmountIsError);

        // -- scoops tastes select --
        vector <VectorIndex> selectedScoopsIndexes = this->scoopsSelectMenu(inputedscoopsAmount);
        for (int i = 0; i < selectedScoopsIndexes.size(); i++)
        {
            VectorIndex selectedIndex = selectedScoopsIndexes.at(i);
            double selectScoopPrice = this->getElementFormIceCreamList(selectedIndex).getPrice();
            string selectScoopName = this->getElementFormIceCreamList(selectedIndex).getName();
            iceCreamReceipt.addItemToReceipt(ReciptItem(selectScoopPrice, selectScoopName));
        }

        return iceCreamReceipt;
    }
};

//--- end Dessert section ------





class DessertsMachine
{
private:
    vector <Coffee> coffeeList;
    vector <Cake> cakeList;
    IceCreamControler iceCreamControler;
    Receipt machineReceipt; // do przeniesienia
    string machineName;// do przeniesienia

public:
    DessertsMachine(string machineName)
        :machineName(machineName)
    {
    }

    void addCoffeeToList(Coffee newCoffee)
    {
        this->coffeeList.push_back(newCoffee);
    }
    void addCakeToList(Cake newCake)
    {
        this->cakeList.push_back(newCake);
    }
    
    int coffeeMenu()
    {
        int coffeeSelect;
        for (int i = 0; i < this->coffeeList.size(); i++)
        {
            cout << i + 1 << " - " << this->coffeeList.at(i).getName();
        }
        cin >> coffeeSelect;
        coffeeSelect--;
        return coffeeSelect;
    }

    bool askIsMilk()
    {
        string select;
        cout << "czy chcesz mleko do kawy?\nT-tak, N-nie\n";
        cin >> select;
        if (select == "T" || select == "t")
        {
            return true;
        }
        if (select == "N" || select == "n")
        {
            return false;
        }
        
    }// do przeniesienia

    

    void frontEndCore()
    {
        int selectedProductType;
        cout << "-----Witaj w automacie--------\n";
        cout << "Wybierz co chcesz kupic\n";
        cout << "Wybierz opcje (numer 1 - lody)\n";
        cout << "Wybierz opcje (numer 2 - ciasto)\n";
        cout << "Wybierz opcje (numer 3 - kawa)\n";
        cin >> selectedProductType;

        if (selectedProductType == 1) //Ice cream path
        {
            Receipt receiptGeneratedByIceCreamMenu = iceCreamControler.menuControler();
            machineReceipt.addReceiptToEachOther(receiptGeneratedByIceCreamMenu);
        }
        else if (selectedProductType == 2) //Cake path
        {
            cout << "wybrales typ: ciasto\n";
        }
        else if (selectedProductType == 3) //Coffee path
        {
            cout << "wybrales typ: kawa\n";
            int coffeeSelect =  coffeeMenu();
            double selectCoffeePrice =  this->coffeeList.at(coffeeSelect).getPrice();
            string selectCoffeeName = this->coffeeList.at(coffeeSelect).getName();
            int isMilk = askIsMilk();
            if (isMilk)
            {
                selectCoffeePrice += 1;
            }
            
            this->machineReceipt.addItemToReceipt(ReciptItem(selectCoffeePrice, selectCoffeeName));
        }
        this->machineReceipt.generateRecipt();
    }

    void machineSetup()
    {
        //1. Budujemy Cake1 .. n


        this->addCoffeeToList(Coffee("coffee1", 11234));
        this->addCoffeeToList(Coffee("coffee3", 22344323543654));

        /*this->addShakeToList(Shake("shake1",11));
        this->addShakeToList(Shake("shake2", 22));
        this->addShakeToList(Shake("shake3", 33));
        this->addShakeToList(Shake("shake4", 44));*/

        this->addCakeToList(Cake("cake1", 1));
        this->addCakeToList(Cake("cake2", 2));
        this->addCakeToList(Cake("cake3", 3));

        IceCream::addNewCupType(IceCreamCupType("slodki rozek", 1.5, 4));
        IceCream::addNewCupType(IceCreamCupType("zwykly", 0.5, 2));
        IceCream::addNewCupType(IceCreamCupType("zwykly-duzy", 1.1, 3));
        iceCreamControler.addIceCreamToList(IceCream("lody1", 44));
        iceCreamControler.addIceCreamToList(IceCream("lody2", 55));
        iceCreamControler.addIceCreamToList(IceCream("lody3", 66));

        //machineToBuild.addShakeToList(Shake("shake1"));
        //machineToBuild.addShakeToList(Shake("shake2"));
        //3. dodajemy do maszyny ciastka , lody ... machineToBuild
    }
};



int main() {
    DessertsMachine machine1("machine1");
    machine1.machineSetup();
    machine1.frontEndCore();
}

//TODO: skonczylme na refactoringu funkcji menu line 201
/*
test
1. front-end core
2. zabezpieczy� menu przez z�ym wyborem
3. zrobi� klase paragon -> done
4. dopisa� pozosta�e funckcjonanosci
5. zrobi� segregace lod�w po typie np. bez laktozy, bez glutenu,
6. zrobi� obs�uge dodatkow dla produkt�w
7. zrobi� mo�liwo�� ponownego wyboru np �eby mo�na by�o kupi� 2 lody i 3 kawy
8. funckje setup przerzu� do klasy machine


skonczy�em na dodaniu kubeczka dla lodow

*/