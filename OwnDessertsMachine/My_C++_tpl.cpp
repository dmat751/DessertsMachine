#include <iostream>
#include <list>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef int VectorIndex;

void PRINT_DEV(string msg)
{
    bool is_print = true;
    if (is_print)
    {
    }
}

//---Start UserInput section---
class UserInputController
{
public:
    static const double validatedInput(double max)
    {
        double userInput;
        int repeat = 1;
        if (max < 0)
        {
            while (true)
            {
                std::cin >> userInput;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(512, '\n');
                    std::cout << "Blad danych, podaj wartosc wieksza od 0!\n";
                }
                else if (userInput > 0)
                {
                    break;
                }
                else
                {
                    std::cout << "Podaj wartosc wieksza od 0!\n";
                }
            }
        }
        else
        {
            while (true)
            {
                std::cin >> userInput;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(512, '\n');
                    std::cout << "Blad danych, podaj wartosc wieksza od 0!\n";
                }
                else if (userInput > 0 && userInput < max)
                {
                    break;
                }
                else
                {
                    std::cout << "Podaj wartosc wieksza od 0 i mniejsza od " << max << "!\n";
                }
            }
        }
        return userInput;
    }

    static const int validatedInput(int max)
    {
        int userInput;
        int repeat = 1;
        if (max < 0)
        {
            while (true)
            {
                std::cin >> userInput;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(512, '\n');
                    std::cout << "Blad danych, podaj wartosc wieksza od 0!\n";
                }
                else if (userInput > 0)
                {
                    break;
                }
                else
                {
                    std::cout << "Podaj wartosc wieksza od 0!\n";
                }
            }
        }
        else
        {
            while (true)
            {
                std::cin >> userInput;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(512, '\n');
                    std::cout << "Blad danych, podaj wartosc wieksza od 0!\n";
                }
                else if (userInput > 0 && userInput < max)
                {
                    break;
                }
                else
                {
                    std::cout << "Podaj wartosc wieksza od 0 i mniejsza od " << max << "!\n";
                }
            }
        }
        return userInput;
    }
};

//-- end UserInput section ---
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
    const double billChange(double &toPay)
    {
        double paid;
        paid = UserInputController::validatedInput(-1);
        while (paid < toPay)
        {
            cout << "Brakuje jeszcze: " << toPay - paid << "\n";
            paid += UserInputController::validatedInput(-1);
        }
        return (paid - toPay);
    }
    void generateRecipt()
    {

        int tabulatorsCount;
        double sum = 0, paid;
        for (int i = 0; i < this->reciptItemList.size(); i++)
        {
            sum += this->reciptItemList.at(i).getPrice();
        }
        cout << "\n--------------------\nDo zaplaty: " << setprecision(2) << fixed << sum;
        cout << "\nZaplacono: ";
        paid = billChange(sum);
        cout << "\n\n\n=================Paragon=================\n| Nazwa \t\t\tCena\t|\n";
        cout << "| ------------------------------------- |\n";
        for (int i = 0; i < this->reciptItemList.size(); i++)
        {
            tabulatorsCount = 4 - ((this->reciptItemList.at(i).getName().length() + 2) / 8);
            cout << "| " << this->reciptItemList.at(i).getName();
            for (int j = 0; j < tabulatorsCount; ++j)
            {
                cout << "\t";
            }
            cout << this->reciptItemList.at(i).getPrice() << " \t|\n";
        }
        cout << "| ------------------------------------- |\n";
        cout << "| Suma:\t\t\t\t" << sum << "\t|\n";
        cout << "| W tym VAT:\t\t\t" << sum * 0.23 << "\t|\n";
        cout << "| Zaplacono:\t\t\t" << paid + sum << "\t|\n";
        cout << "| Reszta:\t\t\t" << paid << "\t|\n";
        cout << "=================Paragon=================\n";
        cout << "koniec paragonu\n";
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

//-----------------------------------------
//-------- start ice cream section -------
class IceCreamCategory
{
private:
    string name;
    int categoryIndex;
    static int categoryIndexGenrator;

public:
    IceCreamCategory()
    {
        this->categoryIndex = categoryIndexGenrator;
        categoryIndexGenrator++;
    }
    IceCreamCategory(string name)
        : name(name)
    {
        this->categoryIndex = categoryIndexGenrator;
        categoryIndexGenrator++;
    }
    int getCategoryID()
    {
        return this->categoryIndex;
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

    static int getAvailableCategoryListSize()
    {
        return availableCategoryList.size();
    }

    static int addNewIceCreamCategory(IceCreamCategory newIceCreamCategory)
    {
        availableCategoryList.push_back(newIceCreamCategory);
        return newIceCreamCategory.getCategoryID();
    }

    static void printIceCreamCategory()
    {
        int availableCategoryListSize = availableCategoryList.size();
        cout << "--------------------\nDostepne rodzaje lodow:\n";
        for (int i = 0; i < availableCategoryListSize; i++)
        {
            cout << i + 1;
            if (i < 9)
            {
                cout << " ";
            }
            cout << " - " << availableCategoryList.at(i).getCategoryName() << "\n";
        }
    }

    // cup section
    static void addNewCupType(IceCreamCupType newType)
    {
        iceCreamCupTypeList.push_back(newType);
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

    static void printAvailableCupList()
    {
        for (int i = 0; i < iceCreamCupTypeList.size(); i++)
        {
            string name = iceCreamCupTypeList.at(i).getAddonName();
            double price = iceCreamCupTypeList.at(i).getAddonPrice();
            int maxScoops = iceCreamCupTypeList.at(i).getMaxScoops();
            int tabulatorsCount = 4 - ((name.length() + 4) / 8);
            cout << (i + 1) << " - " << name;
            for (int j = 0; j < tabulatorsCount; ++j)
            {
                cout << "\t";
            }
            cout << "(cena: " << setprecision(2) << fixed << price << " PLN, max galek: " << maxScoops << ")\n";
        }
    }
    static int getAvailableCupListSize()
    {
        return iceCreamCupTypeList.size();
    }

    // scoop section
    static int getMaxScoopsAmountFromCupList(int itemIndex)
    {
        return iceCreamCupTypeList.at(itemIndex).getMaxScoops();
    }
};
vector<IceCreamCupType> IceCream::iceCreamCupTypeList;
vector<IceCreamCategory> IceCream::availableCategoryList;

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
            cout << "\n--------------------\nWybierz typ kubka\n";
            IceCream::printAvailableCupList();
            cout << "--------------------\nWpisz odpowiedni numer: ";
            bool inputedAmountIsError = true;

            int select = UserInputController::validatedInput(IceCream::getAvailableCupListSize() + 1);
            select--;

            double selectScoopPrice = IceCream::getCupPrice(select);
            string selectScoopName = IceCream::getCupName(select);
            iceCreamReceipt.addItemToReceipt(ReciptItem(selectScoopPrice, selectScoopName));
            return select;
        }

        int scoopsAmountSelect(int maxAmountOfScoopsPerCup)
        {
            int inputedScoopsAmount;
            cout << "--------------------\nIle chcesz galek lodow ?\n";
            inputedScoopsAmount = UserInputController::validatedInput(maxAmountOfScoopsPerCup + 1);
            return inputedScoopsAmount;
        }

        void printIceCreamListSelect(vector<IceCream> &iceCreamList)
        {
            cout << "---------------\n";
            for (int i = 0; i < iceCreamList.size(); i++)
            {
                int tabulatorsCount = 4 - ((iceCreamList.at(i).getName().length() + 5) / 8);
                cout << i + 1;
                if (i < 9)
                {
                    cout << " ";
                }
                cout << " - " << iceCreamList.at(i).getName();
                for (int j = 0; j < tabulatorsCount; ++j)
                {
                    cout << "\t";
                }
                cout << "cena: " << setprecision(2) << fixed << iceCreamList.at(i).getPrice() << " PLN"
                     << "\n";
            }
        }

        vector<MenuSelectItemFrontendBackendConnector> printIceCreamListSelectByCategory(vector<IceCream> &iceCreamList, int categoryIndex = -1)
        {
            vector<MenuSelectItemFrontendBackendConnector> listToReturn;
            if (categoryIndex == -1)
            {
                return listToReturn;
            }
            cout << "---------------\n";
            int counter = 1;
            for (int i = 0; i < iceCreamList.size(); i++)
            {
                if (iceCreamList.at(i).getCategoryIndex() == categoryIndex)
                {
                    int tabulatorsCount = 4 - ((iceCreamList.at(i).getName().length() + 5) / 8);

                    cout << counter;
                    if (counter < 9)
                    {
                        cout << " ";
                    }
                    cout << " - " << iceCreamList.at(i).getName();
                    for (int j = 0; j < tabulatorsCount; ++j)
                    {
                        cout << "\t";
                    }
                    cout << " cena: " << setprecision(2) << fixed << iceCreamList.at(i).getPrice() << " PLN"
                         << "\n";
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

        void iceCreamTypeSelect(vector<IceCream> &iceCreamList, int selectedScoopsAmount, Receipt &iceCreamReceipt)
        {
            int selectedIndex;
            int categorySelectedIndex;
            int iceCreamListSize = iceCreamList.size();
            int sortByCategoryOptionIndex = iceCreamListSize;
            for (int i = 0; i < selectedScoopsAmount; i++)
            {
                cout << "--------------------\nWybierz smak lodow: " << i + 1 << "\n";
                printIceCreamListSelect(iceCreamList);
                cout << iceCreamListSize + 1 << " - Posortuj po kategorii\n";
                selectedIndex = UserInputController::validatedInput(iceCreamListSize + 2);
                selectedIndex--;

                if (selectedIndex == sortByCategoryOptionIndex) // if user select print by category
                {
                    IceCream::printIceCreamCategory();
                    categorySelectedIndex = UserInputController::validatedInput(IceCream::getAvailableCategoryListSize() + 1);
                    categorySelectedIndex--;
                    vector<MenuSelectItemFrontendBackendConnector> frontendBackendConnectionsList =
                        printIceCreamListSelectByCategory(iceCreamList, categorySelectedIndex);
                    int frontendBackendConnectionsListSize = frontendBackendConnectionsList.size();
                    selectedIndex = UserInputController::validatedInput(frontendBackendConnectionsListSize + 1);
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
        cout << "--------------------\nWybrales lody\n";

        // -- cup type select --
        int selectedCupIndex = menuControllerTools.cupTypeSelect(iceCreamReceipt);
        int maxAmountofScoopsPerCup = IceCream::getMaxScoopsAmountFromCupList(selectedCupIndex);

        // -- scoops amounts select --
        int selectedScoopsAmount = menuControllerTools.scoopsAmountSelect(maxAmountofScoopsPerCup);

        // -- scoops tastes select --
        menuControllerTools.iceCreamTypeSelect(this->iceCreamList, selectedScoopsAmount, iceCreamReceipt);

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
    int categoryIndex;
    static int categoryIndexGenrator;

public:
    CoffeeCategory()
    {
        this->categoryIndex = categoryIndexGenrator;
        categoryIndexGenrator++;
    }
    CoffeeCategory(string name)
        : name(name)
    {
        this->categoryIndex = categoryIndexGenrator;
        categoryIndexGenrator++;
    }
    int getCategoryID()
    {
        return this->categoryIndex;
    }
    string getCategoryName()
    {
        return this->name;
    }
};
int CoffeeCategory::categoryIndexGenrator = 0;

class Coffee : public Dessert
{
private:
    static vector<CoffeeCategory> availableCategoryList;
    int categoryIndex;

public:
    Coffee(string name, double price, int categoryID)
        : Dessert(name, price), categoryIndex(categoryID)
    {
    }

    int getCategoryIndex()
    {
        return this->categoryIndex;
    }

    static int addNewCoffeeCategory(CoffeeCategory newCoffeeCategory)
    {
        availableCategoryList.push_back(newCoffeeCategory);
        return newCoffeeCategory.getCategoryID();
    }

    static void printCoffeeCategory()
    {
        int availableCategoryListSize = availableCategoryList.size();
        cout << "--------------------\nDostepne rodzaje kawy:\n";
        for (int i = 0; i < availableCategoryListSize; i++)
        {
            cout << i + 1;
            if (i < 9)
            {
                cout << " ";
            }
            cout << " - " << availableCategoryList.at(i).getCategoryName() << "\n";
        }
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
                 << "Dowolna wartosc - na miejscu\n";
            cin >> selectedOption;
            if (selectedOption == '1')
            {
                cout << "\n--------------------\nWybrany deser zostanie zapakowany w opakowanie.\n";
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
            if (selectedOption == '1')
            {
                cout << "\n--------------------\nDodaje mleko.\n";
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

        void printCoffeeListSelect(vector<Coffee> &coffeeList)
        {
            cout << "---------------\n";
            for (int i = 0; i < coffeeList.size(); i++)
            {
                int tabulatorsCount = 5 - ((coffeeList.at(i).getName().length() + 5) / 8);
                cout << i + 1;
                if (i < 9)
                {
                    cout << " ";
                }
                cout << " - " << coffeeList.at(i).getName();
                for (int j = 0; j < tabulatorsCount; ++j)
                {
                    cout << "\t";
                }
                cout << "cena: " << setprecision(2) << fixed << coffeeList.at(i).getPrice() << " PLN"
                     << "\n";
            }
        }

        vector<MenuSelectItemFrontendBackendConnector> printCoffeeSelectByCategory(vector<Coffee> &coffeeList, int categoryIndex = -1)
        {
            vector<MenuSelectItemFrontendBackendConnector> listToReturn;
            if (categoryIndex == -1)
            {
                return listToReturn;
            }
            cout << "---------------\n";
            int counter = 1;
            for (int i = 0; i < coffeeList.size(); i++)
            {
                if (coffeeList.at(i).getCategoryIndex() == categoryIndex)
                {
                    cout << counter;
                    if (counter < 10)
                    {
                        cout << " ";
                    }
                    int tabulatorsCount = 5 - ((coffeeList.at(i).getName().length() + 5) / 8);
                    cout << " - " << coffeeList.at(i).getName();
                    for (int j = 0; j < tabulatorsCount; ++j)
                    {
                        cout << "\t";
                    }
                    cout << "cena: " << setprecision(2) << fixed << coffeeList.at(i).getPrice() << " PLN"
                         << "\n";
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

        void coffeeTypeSelect(vector<Coffee> &coffeeList, Receipt &coffeeReceipt)
        {
            int selectedIndex;
            int categorySelectedIndex;
            int coffeeListSize = coffeeList.size();
            int sortByCategoryOptionIndex = coffeeListSize;
            cout << "--------------------\nCzy chcesz wziac kawe na wynos?\n";
            takeAwaySelect(coffeeReceipt);
            cout << "--------------------\nWybierz rodzaj kawy: "
                 << "\n";
            printCoffeeListSelect(coffeeList);
            cout << coffeeListSize + 1 << " - Posortuj po kategorii\n";
            selectedIndex = UserInputController::validatedInput(coffeeListSize + 2);
            selectedIndex--;

            if (selectedIndex == sortByCategoryOptionIndex) // if user select print by category
            {
                Coffee::printCoffeeCategory();
                categorySelectedIndex = UserInputController::validatedInput(IceCream::getAvailableCategoryListSize() + 1);
                categorySelectedIndex--;
                vector<MenuSelectItemFrontendBackendConnector> frontendBackendConnectionsList =
                    printCoffeeSelectByCategory(coffeeList, categorySelectedIndex);
                int frontendBackendConnectionsListSize = frontendBackendConnectionsList.size();
                selectedIndex = UserInputController::validatedInput(frontendBackendConnectionsListSize + 1);
                auto backendIndexElement = find_if(frontendBackendConnectionsList.begin(), frontendBackendConnectionsList.end(), [selectedIndex](MenuSelectItemFrontendBackendConnector &obj)
                                                   { return obj.getFrontendListNumber() == selectedIndex; });
                selectedIndex = (*backendIndexElement).getBackendListIndex();
            }
            // -- add selected item to receipt
            double selectCoffeePrice = coffeeList.at(selectedIndex).getPrice();
            string selectCoffeeName = coffeeList.at(selectedIndex).getName();
            coffeeReceipt.addItemToReceipt(ReciptItem(selectCoffeePrice, selectCoffeeName));

            cout << "--------------------\nCzy chcesz dodac mleko?\n";
            milkSelect(coffeeReceipt);
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
        cout << "--------------------\nWybrales kawe\n";

        menuControllerTools.coffeeTypeSelect(this->coffeeList, coffeeReceipt);
        return coffeeReceipt;
    }
};
//-------- end coffee section -------
//-----------------------------------------

//-----------------------------------------
//-------- start Cake section -------
class CakeCategory
{
private:
    string name;
    int categoryIndex;
    static int categoryIndexGenrator;

public:
    CakeCategory()
    {
        this->categoryIndex = categoryIndexGenrator;
        categoryIndexGenrator++;
    }
    CakeCategory(string name)
        : name(name)
    {
        this->categoryIndex = categoryIndexGenrator;
        categoryIndexGenrator++;
    }
    int getCategoryID()
    {
        return this->categoryIndex;
    }
    string getCategoryName()
    {
        return this->name;
    }
};
int CakeCategory::categoryIndexGenrator = 0;

class CakeSprinkles : public DessertAddon
{
private:
public:
    CakeSprinkles(string name, double price)
        : DessertAddon(name, price)
    {
    }
};

class Cake : public Dessert
{
private:
    static vector<CakeCategory> availableCategoryList;
    static vector<CakeSprinkles> cakeSprinklesList;
    int categoryIndex;

public:
    Cake(string name, double price, int categoryID)
        : Dessert(name, price), categoryIndex(categoryID)
    {
    }

    int getCategoryIndex()
    {
        return this->categoryIndex;
    }
    static void addNewCakeSprinkle(CakeSprinkles newSprinkle)
    {
        cakeSprinklesList.push_back(newSprinkle);
    }
    static double getSprinklePrice(int Index)
    {
        double price = cakeSprinklesList.at(Index).getAddonPrice();
        return price;
    }
    static string getSprinkleName(int Index)
    {
        string name = cakeSprinklesList.at(Index).getAddonName();
        return name;
    }
    static int addNewCakeCategory(CakeCategory newCakeCategory)
    {
        availableCategoryList.push_back(newCakeCategory);
        return newCakeCategory.getCategoryID();
    }
    static int getcakeSprinklesListSize()
    {
        return cakeSprinklesList.size();
    }

    static void
    printCakeCategory()
    {
        int availableCategoryListSize = availableCategoryList.size();
        cout << "--------------------\nDostepne rodzaje ciast:\n";
        for (int i = 0; i < availableCategoryListSize; i++)
        {
            cout << i + 1;
            if (i < 9)
            {
                cout << " ";
            }
            cout << " - " << availableCategoryList.at(i).getCategoryName() << "\n";
        }
        //        cout << availableCategoryListSize + 1 << " - Bez kategorii\n";
    }
    static void printCakeSprinklesList()
    {
        cout << "---------------\nDostepne rodzaje posypek:\n";
        for (int i = 0; i < cakeSprinklesList.size(); i++)
        {
            string name = cakeSprinklesList.at(i).getAddonName();
            double price = cakeSprinklesList.at(i).getAddonPrice();
            cout << i + 1;
            if (i < 9)
            {
                cout << " ";
            }
            int tabulatorsCount = 5 - ((name.length() + 5) / 8);
            cout << " - " << name;
            for (int j = 0; j < tabulatorsCount; ++j)
            {
                cout << "\t";
            }
            cout << "cena: " << price << " PLN\n";
        }
    }
};
vector<CakeCategory> Cake::availableCategoryList;
vector<CakeSprinkles> Cake::cakeSprinklesList;
class CakeController
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
                 << "Dowolna wartosc - na miejscu\n";
            cin >> selectedOption;
            if (selectedOption == '1')
            {
                cout << "\n--------------------\nWybrany deser zostanie zapakowany w opakowanie.\n";
                return 1.50;
            }
            return 0;
        }
        void takeAwaySelect(Receipt &cakeReceipt)
        {
            //Cake::printAvaiableCupList();
            cakeReceipt.addItemToReceipt(ReciptItem(isTakeAway(), "Opakowanie"));
        }

        void printCakeListSelect(vector<Cake> &cakeList)
        {
            for (int i = 0; i < cakeList.size(); i++)
            {
                int tabulatorsCount = 5 - ((cakeList.at(i).getName().length() + 5) / 8);
                cout << i + 1;
                if (i < 9)
                {
                    cout << " ";
                }
                cout << " - " << cakeList.at(i).getName();
                for (int j = 0; j < tabulatorsCount; ++j)
                {
                    cout << "\t";
                }
                cout << "cena: " << setprecision(2) << fixed << cakeList.at(i).getPrice() << " PLN"
                     << "\n";
            }
        }
        int cakeSprinklesSelect(Receipt &cakeReceipt)
        {
            cout << "\n--------------------\nWybierz typ posypki\n";
            Cake::printCakeSprinklesList();
            cout << "Wpisz odpowiedni numer: ";
            int select;
            select = UserInputController::validatedInput(Cake::getcakeSprinklesListSize() + 1);
            select--;

            double selectSprinklePrice = Cake::getSprinklePrice(select);
            string selectSprinkleName = Cake::getSprinkleName(select);
            cakeReceipt.addItemToReceipt(ReciptItem(selectSprinklePrice, selectSprinkleName));
            return select;
        }

        vector<MenuSelectItemFrontendBackendConnector> printCakeSelectByCategory(vector<Cake> &cakeList, int categoryIndex = -1)
        {
            vector<MenuSelectItemFrontendBackendConnector> listToReturn;
            if (categoryIndex == -1)
            {
                return listToReturn;
            }
            int counter = 1;
            cout << "---------------\n";
            for (int i = 0; i < cakeList.size(); i++)
            {
                if (cakeList.at(i).getCategoryIndex() == categoryIndex)
                {
                    int tabulatorsCount = 5 - ((cakeList.at(i).getName().length() + 5) / 8);
                    cout << counter;
                    if (i < 9)
                    {
                        cout << " ";
                    }
                    cout << " - " << cakeList.at(i).getName();
                    for (int j = 0; j < tabulatorsCount; ++j)
                    {
                        cout << "\t";
                    }
                    cout << "cena: " << setprecision(2) << fixed << cakeList.at(i).getPrice() << " PLN"
                         << "\n";
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

        void cakeTypeSelect(vector<Cake> &cakeList, Receipt &cakeReceipt)
        {
            int selectedIndex;
            int categorySelectedIndex;
            int cakeListSize = cakeList.size();
            int sortByCategoryOptionIndex = cakeListSize;
            cout << "--------------------\nCzy chcesz wziac ciasto na wynos?\n";
            takeAwaySelect(cakeReceipt);
            cout << "--------------------\nWybierz rodzaj ciasta: "
                 << "\n";
            printCakeListSelect(cakeList);
            cout << cakeListSize + 1 << " - Posortuj po kategorii\n";
            selectedIndex = UserInputController::validatedInput(cakeListSize + 2);
            selectedIndex--;

            if (selectedIndex == sortByCategoryOptionIndex) // if user select print by category
            {
                Cake::printCakeCategory();
                categorySelectedIndex = UserInputController::validatedInput(IceCream::getAvailableCategoryListSize() + 1);
                categorySelectedIndex--;
                vector<MenuSelectItemFrontendBackendConnector> frontendBackendConnectionsList =
                    printCakeSelectByCategory(cakeList, categorySelectedIndex);
                int frontendBackendConnectionsListSize = frontendBackendConnectionsList.size();
                selectedIndex = UserInputController::validatedInput(frontendBackendConnectionsListSize + 1);
                auto backendIndexElement = find_if(frontendBackendConnectionsList.begin(), frontendBackendConnectionsList.end(), [selectedIndex](MenuSelectItemFrontendBackendConnector &obj)
                                                   { return obj.getFrontendListNumber() == selectedIndex; });
                selectedIndex = (*backendIndexElement).getBackendListIndex();
            }
            // -- add selected item to receipt
            double selectCakePrice = cakeList.at(selectedIndex).getPrice();
            string selectCakeName = cakeList.at(selectedIndex).getName();
            cakeReceipt.addItemToReceipt(ReciptItem(selectCakePrice, selectCakeName));
        }
    };

    vector<Cake> cakeList;
    MenuControllerTools menuControllerTools;

public:
    CakeController()
    {
    }
    void addCakeToList(Cake newCake)
    {
        this->cakeList.push_back(newCake);
    }

    Cake getElementFromCakeList(int index)
    {
        return this->cakeList.at(index);
    }

    Receipt menuControler()
    {
        Receipt cakeReceipt;
        // -- user select info --
        cout << "--------------------\nWybrales ciasto\n";

        menuControllerTools.cakeTypeSelect(this->cakeList, cakeReceipt);
        menuControllerTools.cakeSprinklesSelect(cakeReceipt);
        return cakeReceipt;
    }
};
//-------- end Cake section -------
//-----------------------------------------

class DessertsMachine
{
private:
    CoffeeController coffeeController;
    CakeController cakeController;
    IceCreamController iceCreamController;
    Receipt machineReceipt;
    string machineName;

public:
    DessertsMachine(string machineName)
        : machineName(machineName)
    {
    }

    void frontEndCore()
    {
        int selectedProductType;
        int menuSize = 3;
        cout << "----------Witaj !----------\n";

        bool reOrder = false;
        do
        {
            cout << "--------------------\nNa co masz ochote?\n";
            cout << "1 - Lody\n";
            cout << "2 - Ciasto\n";
            cout << "3 - Kawa\n";
            cout << "--------------------\nWpisz odpowiedni numer: \n";
            selectedProductType = UserInputController::validatedInput(menuSize + 1);
            if (selectedProductType == 1) //Ice cream path
            {
                Receipt receiptGeneratedByIceCreamMenu = iceCreamController.menuControler();
                machineReceipt.addReceiptToEachOther(receiptGeneratedByIceCreamMenu);
            }
            else if (selectedProductType == 2) //Cake path
            {
                Receipt receiptGeneratedByCakeMenu = cakeController.menuControler();
                machineReceipt.addReceiptToEachOther(receiptGeneratedByCakeMenu);
            }
            else if (selectedProductType == 3) //Coffee path
            {
                Receipt receiptGeneratedByCoffeeMenu = coffeeController.menuControler();
                machineReceipt.addReceiptToEachOther(receiptGeneratedByCoffeeMenu);
            }
            cout << "--------------------\nCzy chcesz zamowic cos jeszcze?\n";
            cout << "1 - Tak\nDowolna wartosc - Nie\n";
            char reOrderSelect;
            cin >> reOrderSelect;
            if (reOrderSelect == '1')
            {
                reOrder = true;
            }
            else
            {
                reOrder = false;
            }
        } while (reOrder);

        this->machineReceipt.generateRecipt();
    }

    void machineSetup()
    {

        //----------------------------------------------
        //------ start build coffee -----------
        int coffeeCategory1 = Coffee::addNewCoffeeCategory(CoffeeCategory("Bez kofeiny"));
        int coffeeCategory2 = Coffee::addNewCoffeeCategory(CoffeeCategory("Z kofeina"));
        int coffeeCategory3 = Coffee::addNewCoffeeCategory(CoffeeCategory("Bez cukru"));
        int coffeeCategory4 = Coffee::addNewCoffeeCategory(CoffeeCategory("Pozostale"));

        coffeeController.addCoffeeToList(Coffee("Latte bez kofeiny", 11.9, coffeeCategory1));
        coffeeController.addCoffeeToList(Coffee("Espresso bez kofeiny", 6.9, coffeeCategory1));
        coffeeController.addCoffeeToList(Coffee("Latte Machiato bez kofeiny", 12.9, coffeeCategory1));

        coffeeController.addCoffeeToList(Coffee("Latte", 10.9, coffeeCategory2));
        coffeeController.addCoffeeToList(Coffee("Espresso", 5.9, coffeeCategory2));
        coffeeController.addCoffeeToList(Coffee("Latte Machiato", 11.9, coffeeCategory2));

        coffeeController.addCoffeeToList(Coffee("Latte bez cukru", 10.4, coffeeCategory3));
        coffeeController.addCoffeeToList(Coffee("Espresso bez cukru", 5.4, coffeeCategory3));
        coffeeController.addCoffeeToList(Coffee("Latte Machiato bez cukru", 11.4, coffeeCategory3));

        coffeeController.addCoffeeToList(Coffee("Ristretto Pozostale", 10.4, coffeeCategory4));
        coffeeController.addCoffeeToList(Coffee("Espresso doppio Pozostale", 5.4, coffeeCategory4));
        coffeeController.addCoffeeToList(Coffee("Cappuccino Pozostale", 11.4, coffeeCategory4));
        coffeeController.addCoffeeToList(Coffee("Macchiato Pozostale", 10.4, coffeeCategory4));
        coffeeController.addCoffeeToList(Coffee("Lungo / americano Pozostale", 5.4, coffeeCategory4));
        coffeeController.addCoffeeToList(Coffee("Mocha Pozostale", 11.4, coffeeCategory4));
        coffeeController.addCoffeeToList(Coffee("Romano", 21.4, coffeeCategory4));
        //------ end build coffee -----------
        //----------------------------------------------

        //----------------------------------------------
        //------ start build Cake -----------
        int cakeCategory1 = Cake::addNewCakeCategory(CakeCategory("Owocowe"));
        int cakeCategory2 = Cake::addNewCakeCategory(CakeCategory("Z czekolada"));
        int cakeCategory3 = Cake::addNewCakeCategory(CakeCategory("Bez glutenu"));

        cakeController.addCakeToList(Cake("Szarlotka", 2.7, cakeCategory1));
        cakeController.addCakeToList(Cake("Ciasto wisniowe", 3.2, cakeCategory1));
        cakeController.addCakeToList(Cake("Placek brzoskwiniowy", 3.1, cakeCategory1));

        cakeController.addCakeToList(Cake("Mazurek czekoladowy", 2.9, cakeCategory2));
        cakeController.addCakeToList(Cake("Muffinki z czekolada", 3.5, cakeCategory2));
        cakeController.addCakeToList(Cake("Sernik z polewa czekoladowa", 3.0, cakeCategory2));

        cakeController.addCakeToList(Cake("Szarlotka bez glutenu", 2.8, cakeCategory3));
        cakeController.addCakeToList(Cake("Ciasto w  isniowe bez glutenu", 3.4, cakeCategory3));
        cakeController.addCakeToList(Cake("Sernik bez glutenu", 3.3, cakeCategory3));
        cakeController.addCakeToList(Cake("Tort bez glutenu", 10.3, cakeCategory3));
        cakeController.addCakeToList(Cake("Tort sliwkowy bez glutenu", 26.3, cakeCategory3));
        cakeController.addCakeToList(Cake("Tort Jubilata bez glutenu", 30.3, cakeCategory3));

        Cake::addNewCakeSprinkle(CakeSprinkles("Czekoladowa", 0.65));
        Cake::addNewCakeSprinkle(CakeSprinkles("Kolorowe Cukierki", 0.9));
        Cake::addNewCakeSprinkle(CakeSprinkles("Zelki", 0.7));
        Cake::addNewCakeSprinkle(CakeSprinkles("Suszone owoce", 0.69));
        Cake::addNewCakeSprinkle(CakeSprinkles("EKO", 2.69));
        Cake::addNewCakeSprinkle(CakeSprinkles("Krolewska", 2.69));
        //------ end build Cake -----------
        //----------------------------------------------

        //----------------------------------------------
        //------ start build ice cream -----------
        IceCream::addNewCupType(IceCreamCupType("Slodki rozek", 1.5, 4));
        IceCream::addNewCupType(IceCreamCupType("Plastikowy kubeczek", 0.5, 2));
        IceCream::addNewCupType(IceCreamCupType("Wafelkowa salaterka", 1.1, 3));
        IceCream::addNewCupType(IceCreamCupType("kubek ECO", 5.1, 3));

        int iceCreamCategory1 = IceCream::addNewIceCreamCategory(IceCreamCategory("Bez laktozy"));
        int iceCreamCategory2 = IceCream::addNewIceCreamCategory(IceCreamCategory("Bez glutenu"));
        int iceCreamCategory3 = IceCream::addNewIceCreamCategory(IceCreamCategory("Klasyczne"));
        int iceCreamCategory4 = IceCream::addNewIceCreamCategory(IceCreamCategory("Pozostale"));

        iceCreamController.addIceCreamToList(IceCream("Karmelowy bez laktozy", 2.5, iceCreamCategory1));
        iceCreamController.addIceCreamToList(IceCream("Waniliowy bez laktozy", 2.3, iceCreamCategory1));
        iceCreamController.addIceCreamToList(IceCream("Malinowy bez laktozy", 2.4, iceCreamCategory1));
        iceCreamController.addIceCreamToList(IceCream("Ananasowy bez laktozy", 2.4, iceCreamCategory1));
        iceCreamController.addIceCreamToList(IceCream("Borowkowy bez laktozy", 2.4, iceCreamCategory1));

        iceCreamController.addIceCreamToList(IceCream("Karmelowy bez glutenu", 2.6, iceCreamCategory2));
        iceCreamController.addIceCreamToList(IceCream("Waniliowy bez glutenu", 2.4, iceCreamCategory2));
        iceCreamController.addIceCreamToList(IceCream("Malinowy bez glutenu", 2.5, iceCreamCategory2));
        iceCreamController.addIceCreamToList(IceCream("Kiwi bez glutenu", 2.5, iceCreamCategory2));

        iceCreamController.addIceCreamToList(IceCream("Karmelowy", 2, iceCreamCategory3));
        iceCreamController.addIceCreamToList(IceCream("Waniliowy", 1.8, iceCreamCategory3));
        iceCreamController.addIceCreamToList(IceCream("Malinowy", 1.9, iceCreamCategory3));

        iceCreamController.addIceCreamToList(IceCream("Malinowy - pozostale", 1.9, iceCreamCategory4));

        //------ end build ice cream -----------
        //----------------------------------------------
    }
};

int main()
{
    DessertsMachine machine1("machine1");
    machine1.machineSetup();
    machine1.frontEndCore();
    // system("PAUSE");
}
