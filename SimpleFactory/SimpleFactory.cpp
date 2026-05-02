#include <iostream>
using namespace std;

class Burger
{

public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class classicBurger : public Burger
{

public:
    void prepare() override
    {
        cout << "Preparing classic burger" << endl;
    }
};

class standardBurger : public Burger
{

public:
    void prepare() override
    {
        cout << "Preparing standard burger" << endl;
    }
};

class specialBurger : public Burger
{

public:
    void prepare() override
    {
        cout << "Prearing special burger" << endl;
    }
};

class SimpleFactory
{
private:
    // string type;

public:
    Burger *createBurger(string type)
    {
        if (type == "basic")
        {
            return new classicBurger();
        }
        else if (type == "standard")
        {
            return new standardBurger();
        }
        else if (type == "premium")
        {
            return new specialBurger();
        }
        else
        {
            cout << "This type of burger does not exists" << endl;
            return nullptr;
        }
    }
};

int main()
{
    string type = "premium";

    SimpleFactory *factory = new SimpleFactory();
    Burger *burger = factory->createBurger(type);

    burger->prepare();

    return 0;
}