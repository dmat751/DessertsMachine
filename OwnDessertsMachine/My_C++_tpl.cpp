#include <iostream>
#include <list>
#include <vector>
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
        : price(price), name(name)
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
    vector<ReciptItem> reciptItemList;

public:
    Receipt()
    {
    }
    void addItemToReceipt(ReciptItem newReceiptItem)
    {
        reciptItemList.push_back(newReceiptItem);
    }
    void addReceiptToEachOther(Receipt &receiptToAdd)
    {
        int itemAmount = receiptToAdd.reciptItemList.size();
        for (int i = 0; i < itemAmount; i++)
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
class DessertAddon
{
private:
    string name;
    double price;

public:
    DessertAddon(string name, double price)
        : name(name), price(price)
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

//--- end DessertAddon section ------

//--- start Dessert section ------
class Dessert
{
private:
    string name;
    double price;

public:
    Dessert(string name, double price)
        : name(name), price(price)
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

class Cake : public Dessert
{
private:
public:
    Cake(string name, double price)
        : Dessert(name, price)
    {
    }
};

//-----------------------------------------
//-------- start ice cream section -------
class IceCreamCategory
{
private:
    string name;
    int ID;
    static int categoryIndexGenrator;

public:
    IceCreamCategory()
    {
        this->ID = categoryIndexGenrator;
        categoryIndexGenrator++;
    }
    IceCreamCategory(string name)
        : name(name)
    {
        this->ID = categoryIndexGenrator;
        categoryIndexGenrator++;
    }
    int getCategoryID()
    {
        return this->ID;
    }
    string getCategoryName()
    {
        return this->name;
    }
};
int IceCreamCategory::categoryIndexGenrator = 0;

class IceCreamCupType : public DessertAddon
{
private:
    int maxScoops;

public:
    IceCreamCupType(string name, double price, int maxScoops)
        : maxScoops(maxScoops), DessertAddon(name, price)
    {
    }
    int getMaxScoops()
    {
        return this->maxScoops;
    }
};

class IceCream : public Dessert
{
private:
    static vector<IceCreamCupType> iceCreamCupTypeList;
    static vector<IceCreamCategory> availableCategoryList;
    int categoryIndex;

public:
    IceCream(string name, double price, int categoryIndex)
        : Dessert(name, price), categoryIndex(categoryIndex)
    {
    }

    int getCategoryIndex()
    {
        return this->categoryIndex;
    }

    static int addNewIceCreamCategory(IceCreamCategory newIceCreamCategory)
    {
        availableCategoryList.push_back(newIceCreamCategory);
        return newIceCreamCategory.getCategoryID();
    }

    static void printIceCreamCategory()
    {
        int availableCategoryListSize = availableCategoryList.size();
        cout << "dostepne kategorie lodow:\n";
        for (int i = 0; i < availableCategoryListSize; i++)
        {
            cout << i + 1 << " - " << availableCategoryList.at(i).getCategoryName() << "\n";
        }
    }

    static void addNewCupType(IceCreamCupType newType)
    {
        iceCreamCupTypeList.push_back(newType);
    }

    static int getMaxScoopsAmountFromCupList(int itemIndex)
    {
        return iceCreamCupTypeList.at(itemIndex).getMaxScoops();
    }

    static double getCupPrice(int cupIndex)
    {
        double price = iceCreamCupTypeList.at(cupIndex).getAddonPrice();
        return price;
    }

    static string getCupName(int cupIndex)
    {
        string name = iceCreamCupTypeList.at(cupIndex).getAddonName();
        return name;
    }

    static void printAvaiableCupList()
    {
        for (int i = 0; i < iceCreamCupTypeList.size(); i++)
        {
            string name = iceCreamCupTypeList.at(i).getAddonName();
            double price = iceCreamCupTypeList.at(i).getAddonPrice();
            int maxScoops = iceCreamCupTypeList.at(i).getMaxScoops();
            cout << (i + 1) << " - " << name << " cena: " << price << " max galek: " << maxScoops << "\n";
        }
    }
};
vector<IceCreamCupType> IceCream::iceCreamCupTypeList;
vector<IceCreamCategory> IceCream::availableCategoryList;

class MenuSelectItemFrontendBackendConnector
{
private:
    int frontendListNumber;
    int backendListIndex;

public:
    MenuSelectItemFrontendBackendConnector() {}
    MenuSelectItemFrontendBackendConnector(int frontendListNumber, int backendListIndex)
        : frontendListNumber(frontendListNumber), backendListIndex(backendListIndex)
    {
    }
    int getFrontendListNumber()
    {
        return this->frontendListNumber;
    }
    int getBackendListIndex()
    {
        return this->backendListIndex;
    }
};

class IceCreamController
{
private:
    class MenuControllerTools
    {
    public:
        MenuControllerTools()
        {
        }
        int cupTypeSelect(Receipt &iceCreamReceipt)
        {
            IceCream::printAvaiableCupList();
            cout << "podaj numer: ";
            int select;
            cin >> select;
            select--;

            double selectScoopPrice = IceCream::getCupPrice(select);
            string selectScoopName = IceCream::getCupName(select);
            iceCreamReceipt.addItemToReceipt(ReciptItem(selectScoopPrice, selectScoopName));
            return select;
        }

        int scoopsAmountSelect(int maxAmountOfScoopsPerCup)
        {
            int inputedScoopsAmount;
            bool inputedScoopsAmountIsError = true;
            do
            {
                cout << "ile galek lodow chcesz?\n";
                cin >> inputedScoopsAmount;
                if (inputedScoopsAmount <= maxAmountOfScoopsPerCup)
                {
                    inputedScoopsAmountIsError = false;
                }
                else
                {
                    cout << "podano zla ilosc galek lodow\n";
                }
            } while (inputedScoopsAmountIsError);

            return inputedScoopsAmount;
        }

        void printIceCreamListSelect(vector<IceCream> &iceCreamList)
        {
            for (int i = 0; i < iceCreamList.size(); i++)
            {
                cout << i + 1 << " - " << iceCreamList.at(i).getName() << "\n";
            }
        }

        vector<MenuSelectItemFrontendBackendConnector> printIceCreamListSelectByCategory(vector<IceCream> &iceCreamList, int categoryIndex = -1)
        {
            vector<MenuSelectItemFrontendBackendConnector> listToReturn;
            if (categoryIndex == -1)
            {
                return listToReturn;
            }
            int counter = 1;
            for (int i = 0; i < iceCreamList.size(); i++)
            {
                if (iceCreamList.at(i).getCategoryIndex() == categoryIndex)
                {
                    cout << counter << " - " << iceCreamList.at(i).getName() << "\n";
                    listToReturn.push_back(MenuSelectItemFrontendBackendConnector(counter, i));
                    counter++;
                }
                else
                {
                    continue;
                }
            }
            return listToReturn;
        }

        void iceCreamTasteSelect(vector<IceCream> &iceCreamList, int selectedScoopsAmount, Receipt &iceCreamReceipt)
        {
            int selectedIndex;
            int categorySelectedIndex;
            int iceCreamListSize = iceCreamList.size();
            int sortByCategorySelectIndex = iceCreamListSize;
            for (int i = 0; i < selectedScoopsAmount; i++)
            {
                cout << "wybierz smak: " << i + 1 << "\n";
                printIceCreamListSelect(iceCreamList);
                cout << iceCreamListSize + 1 << " - posortuj po kategorii\n";
                cin >> selectedIndex;
                selectedIndex--;

                //TODO: popracowac na rozwiazaniem z indexem przy kategorii
                // 1. zmienic architekture

                if (selectedIndex == sortByCategorySelectIndex) // if user select print by category
                {
                    IceCream::printIceCreamCategory();
                    cin >> categorySelectedIndex;
                    categorySelectedIndex--;
                    vector<MenuSelectItemFrontendBackendConnector> frontendBackendConnectionsList =
                        printIceCreamListSelectByCategory(iceCreamList, categorySelectedIndex);
                    cin >> selectedIndex;
                    auto backendIndexElement = find_if(frontendBackendConnectionsList.begin(), frontendBackendConnectionsList.end(), [selectedIndex](MenuSelectItemFrontendBackendConnector &obj)
                                                       { return obj.getFrontendListNumber() == selectedIndex; });
                    selectedIndex = (*backendIndexElement).getBackendListIndex();
                }

                // -- add selected item to receipt
                double selectScoopPrice = iceCreamList.at(selectedIndex).getPrice();
                string selectScoopName = iceCreamList.at(selectedIndex).getName();
                iceCreamReceipt.addItemToReceipt(ReciptItem(selectScoopPrice, selectScoopName));
            }
        }
    };

    vector<IceCream> iceCreamList;
    MenuControllerTools menuControllerTools;

public:
    IceCreamController()
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
        // -- user select info --
        cout << "wybrales typ: lody\n";

        // -- cup type select --
        int selectedCupIndex = menuControllerTools.cupTypeSelect(iceCreamReceipt);
        int maxAmountofScoopsPerCup = IceCream::getMaxScoopsAmountFromCupList(selectedCupIndex);

        // -- scoops amounts select --
        int selectedScoopsAmount = menuControllerTools.scoopsAmountSelect(maxAmountofScoopsPerCup);

        // -- scoops tastes select --
        menuControllerTools.iceCreamTasteSelect(this->iceCreamList, selectedScoopsAmount, iceCreamReceipt);

        return iceCreamReceipt;
    }
};
//-------- end ice cream section -------
//-----------------------------------------

//-----------------------------------------
//-------- start coffee section -------
class CoffeeCategory
{
private:
    string name;
    int ID;
    static int IDGenrator;

public:
    CoffeeCategory()
    {
        this->ID = IDGenrator;
        IDGenrator++;
    }
    CoffeeCategory(string name)
        : name(name)
    {
        this->ID = IDGenrator;
        IDGenrator++;
    }
    int getCategoryID()
    {
        return this->ID;
    }
    string getCategoryName()
    {
        return this->name;
    }
};
int CoffeeCategory::IDGenrator = 0;

class Coffee : public Dessert
{
private:
    static vector<CoffeeCategory> availableCategoryList;
    int categoryID;

public:
    Coffee(string name, double price, int categoryID)
        : Dessert(name, price), categoryID(categoryID)
    {
    }

    int getCategoryID()
    {
        return this->categoryID;
    }

    static int getCategoryIDByIndex(int categoryIndex)
    {
        return availableCategoryList.at(categoryIndex).getCategoryID();
    }

    static int addNewCoffeeCategory(CoffeeCategory newCoffeeCategory)
    {
        availableCategoryList.push_back(newCoffeeCategory);
        return newCoffeeCategory.getCategoryID();
    }

    static void printCoffeeCategory()
    {
        int availableCategoryListSize = availableCategoryList.size();
        cout << "dostepne kategorie Kawy:\n";
        for (int i = 0; i < availableCategoryListSize; i++)
        {
            cout << i + 1 << " - " << availableCategoryList.at(i).getCategoryName() << "\n";
        }
        cout << availableCategoryListSize + 1 << " - bez kategorii\n";
    }
};
vector<CoffeeCategory> Coffee::availableCategoryList;

class CoffeeController
{
private:
    class MenuControllerTools
    {
    public:
        MenuControllerTools()
        {
        }
        const double isTakeAway()
        {
            char selectedOption;
            cout << "1 - Na wynos\n"
                 << "Dowolna wartosc - Na miejscu\n";
            cin >> selectedOption;
            if (selectedOption == '1')
            {
                cout << "\n-------\nWybrany deser zostanie zapakowany w opakowanie.\n";
                return 1.50;
            }
            return 0;
        }
        const double isWithMilk()
        {
            char selectedOption;
            cout << "1 - Z mlekiem\n"
                 << "Dowolna wartosc - Bez mleka\n";
            cin >> selectedOption;
            if (selectedOption == 1)
            {
                cout << "\n-------\nDodaje mleko.\n";
                return 1.20;
            }
            return 0;
        }
        void takeAwaySelect(Receipt &coffeeReceipt)
        {
            //Coffee::printAvaiableCupList();
            coffeeReceipt.addItemToReceipt(ReciptItem(isTakeAway(), "Opakowanie"));
        }
        void milkSelect(Receipt &coffeeReceipt)
        {
            //Coffee::printAvaiableCupList();
            coffeeReceipt.addItemToReceipt(ReciptItem(isWithMilk(), "Mleko"));
        }
        void printCoffeeListSelect(vector<Coffee> &coffeeList, int categoryID = 0)
        {
            for (int i = 0; i < coffeeList.size(); i++)
            {
                if (categoryID != 0 && coffeeList.at(i).getCategoryID() == categoryID)
                {
                    cout << i + 1 << " - " << coffeeList.at(i).getName() << "\n";
                }
                else
                {
                    cout << i + 1 << " - " << coffeeList.at(i).getName() << "\n";
                }
            }
        }

        void coffeeTypeSelect(vector<Coffee> &coffeeList, Receipt &coffeeReceipt)
        {
            int selectedIndex;
            int categorySelectedIndex;
            int coffeeListSize = coffeeList.size();
            cout << "Czy chcesz wziac kawe na wynos?\n";
            takeAwaySelect(coffeeReceipt);
            cout << "Wybierz typ kawy: "
                 << "\n";
            printCoffeeListSelect(coffeeList);
            cout << coffeeListSize + 1 << " - posortuj po kategorii\n";
            cin >> selectedIndex;
            selectedIndex--;

            //TODO: popracowac na rozwiazaniem z indexem przy kategorii
            // 1. usuac bez kategori konstruktor
            // 2. zminic numeracji ID na index
            // 3. zmienic architekture

            if (selectedIndex == coffeeListSize) // if user select print by category
            {
                Coffee::printCoffeeCategory();
                cin >> categorySelectedIndex;
                categorySelectedIndex--;
                int categoryID = Coffee::getCategoryIDByIndex(categorySelectedIndex);
                printCoffeeListSelect(coffeeList, categoryID);
            }
            cout << "Czy chcesz dodac mleko?\n";
            milkSelect(coffeeReceipt);
            // -- add selected item to receipt
            double selectCoffeePrice = coffeeList.at(selectedIndex).getPrice();
            string selectCoffeeName = coffeeList.at(selectedIndex).getName();
            coffeeReceipt.addItemToReceipt(ReciptItem(selectCoffeePrice, selectCoffeeName));
        }
    };

    vector<Coffee> coffeeList;
    MenuControllerTools menuControllerTools;

public:
    CoffeeController()
    {
    }
    void addCoffeeToList(Coffee newCoffee)
    {
        this->coffeeList.push_back(newCoffee);
    }

    Coffee getElementFromCoffeeList(int index)
    {
        return this->coffeeList.at(index);
    }

    Receipt menuControler()
    {
        Receipt coffeeReceipt;
        // -- user select info --
        cout << "wybrales typ: Kawa\n";
        // -- cup type select --
        //int selectedCupIndex = menuControllerTools.coffeeTypeSelect(coffeeReceipt);
        //int maxAmountofScoopsPerCup = IceCream::getMaxScoopsAmountFromCupList(selectedCupIndex);

        // -- scoops amounts select --
        //int selectedScoopsAmount = menuControllerTools.scoopsAmountSelect(maxAmountofScoopsPerCup);

        // -- scoops tastes select --
        menuControllerTools.coffeeTypeSelect(this->coffeeList, coffeeReceipt);
        return coffeeReceipt;
    }
};
//-------- end coffee section -------
//-----------------------------------------

class DessertsMachine
{
private:
    CoffeeController coffeeController;
    vector<Cake> cakeList;
    IceCreamController iceCreamController;
    Receipt machineReceipt;
    string machineName;

public:
    DessertsMachine(string machineName)
        : machineName(machineName)
    {
    }

  
    void addCakeToList(Cake newCake)
    {
        this->cakeList.push_back(newCake);
    }

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
            Receipt receiptGeneratedByIceCreamMenu = iceCreamController.menuControler();
            machineReceipt.addReceiptToEachOther(receiptGeneratedByIceCreamMenu);
        }
        else if (selectedProductType == 2) //Cake path
        {
            cout << "wybrales typ: ciasto\n";
        }
        else if (selectedProductType == 3) //Coffee path
        {
            Receipt receiptGeneratedByCoffeeMenu = coffeeController.menuControler();
            machineReceipt.addReceiptToEachOther(receiptGeneratedByCoffeeMenu);
        }
        this->machineReceipt.generateRecipt();
    }

    void machineSetup()
    {
        //1. Budujemy Cake1 .. n

        //----------------------------------------------
        //------ start build coffee -----------
        //IceCream::addNewCupType(IceCreamCupType("slodki rozek", 1.5, 4));
        //IceCream::addNewCupType(IceCreamCupType("zwykly", 0.5, 2));
        //IceCream::addNewCupType(IceCreamCupType("zwykly-duzy", 1.1, 3));
        int coffeeCategory1 = Coffee::addNewCoffeeCategory(CoffeeCategory("Bez kofeiny"));
        int coffeeCategory2 = Coffee::addNewCoffeeCategory(CoffeeCategory("Z kofeiną"));
        int coffeeCategory3 = Coffee::addNewCoffeeCategory(CoffeeCategory("Bez cukru"));

        coffeeController.addCoffeeToList(Coffee("Latte bez kofeiny", 44, coffeeCategory1));
        coffeeController.addCoffeeToList(Coffee("Kawa czarna bez kofeiny", 45, coffeeCategory1));
        coffeeController.addCoffeeToList(Coffee("Latte Machiato bez kofeiny", 46, coffeeCategory1));

        coffeeController.addCoffeeToList(Coffee("Latte", 55, coffeeCategory2));
        coffeeController.addCoffeeToList(Coffee("Espresso", 56, coffeeCategory2));
        coffeeController.addCoffeeToList(Coffee("Latte Machiato", 57, coffeeCategory2));

        coffeeController.addCoffeeToList(Coffee("Latte bez cukru", 50, coffeeCategory3));
        coffeeController.addCoffeeToList(Coffee("Espresso bez cukru", 51, coffeeCategory3));
        coffeeController.addCoffeeToList(Coffee("Latte Machiato bez cukru", 52, coffeeCategory3));
        //------ end build coffee -----------
        //----------------------------------------------

        /*this->addShakeToList(Shake("shake1",11));
        this->addShakeToList(Shake("shake2", 22));
        this->addShakeToList(Shake("shake3", 33));
        this->addShakeToList(Shake("shake4", 44));*/

        this->addCakeToList(Cake("cake1", 1));
        this->addCakeToList(Cake("cake2", 2));
        this->addCakeToList(Cake("cake3", 3));

        //----------------------------------------------
        //------ start build ice cream -----------
        IceCream::addNewCupType(IceCreamCupType("slodki rozek", 1.5, 4));
        IceCream::addNewCupType(IceCreamCupType("zwykly", 0.5, 2));
        IceCream::addNewCupType(IceCreamCupType("zwykly-duzy", 1.1, 3));

        int iceCreamCategory1 = IceCream::addNewIceCreamCategory(IceCreamCategory("Bez laktozy"));
        int iceCreamCategory2 = IceCream::addNewIceCreamCategory(IceCreamCategory("Bez glutenu"));
        int iceCreamCategory3 = IceCream::addNewIceCreamCategory(IceCreamCategory("inne"));

        iceCreamController.addIceCreamToList(IceCream("smak1 bez laktozy", 44, iceCreamCategory1));
        iceCreamController.addIceCreamToList(IceCream("smak2 bez laktozy", 45, iceCreamCategory1));
        iceCreamController.addIceCreamToList(IceCream("smak3 bez laktozy", 46, iceCreamCategory1));

        iceCreamController.addIceCreamToList(IceCream("smak21 bez glutenu", 55, iceCreamCategory2));
        iceCreamController.addIceCreamToList(IceCream("smak22 bez glutenu", 56, iceCreamCategory2));
        iceCreamController.addIceCreamToList(IceCream("smak23 bez glutenu", 57, iceCreamCategory2));

        iceCreamController.addIceCreamToList(IceCream("smak31", 66, iceCreamCategory3));
        iceCreamController.addIceCreamToList(IceCream("smak32", 67, iceCreamCategory3));
        iceCreamController.addIceCreamToList(IceCream("smak33", 68, iceCreamCategory3));

        //------ end build ice cream -----------
        //----------------------------------------------
    }
};

int main()
{
    DessertsMachine machine1("machine1");
    machine1.machineSetup();
    machine1.frontEndCore();
    system("PAUSE");
}

//TODO
/*
1. paragon podsumowanie + wprowadzenie kwoty przez usera + wydanie reszty + validacja 
2. dorobić obsługę kategorii w lodach
3. menu dla coffee 
4. menu dla cake
5. validacja 
6. lody z alkoholem
7. możliwość wyboru i lodow i ciastek np kupić 2 loady i 3 ciasta
8. system do wydawnaie reszty  monet


TODO Szymon
1. menu dla coffee 
2. menu dla cake

*/