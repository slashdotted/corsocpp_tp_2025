#include <iostream>
#include <stdexcept>
using namespace std;

struct Data
{
    Data() { cout << "New data" << endl; }
    ~Data() { cout << "Destroying data" << endl; }
};

struct MyContainer
{
    MyContainer()
        : m_x{new Data}
        , m_y{new Data}
    {
        cout << "New MyContainer" << endl;
    }

    // Gestisco la copia
    MyContainer(const MyContainer &o)
        : m_x{new Data{*o.m_x}}
        , m_y{new Data{*o.m_y}}
    {}

    // Oppure impedisco la copia
    // MyContainer(const MyContainer &o) = delete;

    MyContainer &operator=(const MyContainer &o)
    {
        *m_x = *o.m_x;
        *m_y = *o.m_y;
        return *this;
    }

    // Oppure impedisco la copia
    //MyContainer& operator=(const MyContainer&) = delete;

    void foo()
    {
        // Questo con operatore di assegnamento di copia private
        // funziona, con = delete no
        // MyContainer k;
        // k = *this;
    }

    ~MyContainer()
    {
        delete m_x;
        delete m_y;
        cout << "Destroying MyContainer" << endl;
    }

private:
    // Soluzione per impedire la copia pre C++-111
    //MyContainer(const MyContainer&) {}
    //MyContainer& operator=(const MyContainer&) {return *this;};

    Data *m_x;
    Data *m_y;
};

int main()
{
    MyContainer x;
}
