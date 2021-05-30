#include <iostream>
#include <list>
#include <vector>
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

class IceCreamCupType: public DessertAddon
{
private:
    int maxScoops;
public:
    IceCreamCupType(string name, double price, int maxScoops)
        :maxScoops(maxScoops), DessertAddon(name,  price)
    {}
    int getMaxScoops()
    {
        return this->maxScoops;
    }
};

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
        :Dessert(name,price)
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

class DessertsMachine
{
private:

    vector <Coffee> coffeeList;
    vector <Cake> cakeList;
    vector <IceCream> iceCreamList;
    Receipt machineReceipt;
    string machineName;
    typedef int VectorIndex;

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
    void addiceCreamToList(IceCream newiceCream)
    {
        this->iceCreamList.push_back(newiceCream);
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
        
    }

    //------------------------------------
    // ice cream section
    int iceCreamMenu()
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
                selectedScoopsIndexes.push_back(iceCreamMenu());
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

    // ice cream section
    //------------------------------------

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
            vector <VectorIndex> selectedScoopsIndexes = scoopsSelectMenu(inputedscoopsAmount); 
            for (int i = 0; i < selectedScoopsIndexes.size(); i++)
            {
                VectorIndex selectedIndex = selectedScoopsIndexes.at(i);
                double selectScoopPrice = this->iceCreamList.at(selectedIndex).getPrice();
                string selectScoopName = this->iceCreamList.at(selectedIndex).getName();
                this->machineReceipt.addItemToReceipt(ReciptItem(selectScoopPrice, selectScoopName));
            }
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
};

void machineSetup(DessertsMachine& machineToBuild)
{
    //1. Budujemy Cake1 .. n


    machineToBuild.addCoffeeToList(Coffee("coffee1", 11234));
    machineToBuild.addCoffeeToList(Coffee("coffee3",22344323543654));

    /*machineToBuild.addShakeToList(Shake("shake1",11));
    machineToBuild.addShakeToList(Shake("shake2", 22));
    machineToBuild.addShakeToList(Shake("shake3", 33));
    machineToBuild.addShakeToList(Shake("shake4", 44));*/

    machineToBuild.addCakeToList(Cake("cake1",1));
    machineToBuild.addCakeToList(Cake("cake2", 2));
    machineToBuild.addCakeToList(Cake("cake3", 3));

    IceCream::addNewCupType(IceCreamCupType("slodki rozek", 1.5, 4));
    IceCream::addNewCupType(IceCreamCupType("zwykly", 0.5, 2));
    IceCream::addNewCupType(IceCreamCupType("zwykly-duzy", 1.1, 3));
    machineToBuild.addiceCreamToList(IceCream("lody1", 44));
    machineToBuild.addiceCreamToList(IceCream("lody2", 55));
    machineToBuild.addiceCreamToList(IceCream("lody3", 66));

    //machineToBuild.addShakeToList(Shake("shake1"));
    //machineToBuild.addShakeToList(Shake("shake2"));
    //3. dodajemy do maszyny ciastka , lody ... machineToBuild
}

int main() {
    DessertsMachine machine1("machine1");
    machineSetup(machine1);
    machine1.frontEndCore();
}

//TODO:
/*
1. front-end core
2. zabezpieczyæ menu przez z³ym wyborem
3. zrobiæ klase paragon -> done
4. dopisaæ pozosta³e funckcjonanosci
5. zrobiæ segregace lodów po typie np. bez laktozy, bez glutenu,
6. zrobiæ obs³uge dodatkow dla produktów
7. zrobiæ mo¿liwoœæ ponownego wyboru np ¿eby mo¿na by³o kupiæ 2 lody i 3 kawy
8. funckje setup przerzuæ do klasy machine


skonczy³em na dodaniu kubeczka dla lodow

*/