#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

struct Data
{
    Data() { cout << "New data" << endl; }
    ~Data() { cout << "Destroying data" << endl; }
};

struct MyContainer
{
    MyContainer(unsigned int size = 10)
        : m_array{new Data[size]}
        , m_size{size}
    {
        cout << "New MyContainer" << endl;
    }

    ~MyContainer()
    {
        cout << "Destroying MyContainer" << endl;
        delete[] m_array;
    }

    // copy constructor
    MyContainer(const MyContainer &o)
        : m_array{new Data[o.m_size]}
        , m_size{o.m_size}
    {
        for (auto i{0}; i < m_size; ++i) {
            m_array[i] = o.m_array[i];
        }
        cout << "Copy constructing MyContainer" << endl;
    }

    // move constructor
    MyContainer(MyContainer &&o)
        : m_array{o.m_array}
        , m_size{o.m_size}
    {
        o.m_array = nullptr;
        o.m_size = 0;
        cout << "Move constructing MyContainer" << endl;
    }

    // copy assignment operator
    MyContainer &operator=(const MyContainer &o)
    {
        if (m_size != o.m_size) {
            throw "Error: invalid size";
        }
        for (auto i{0}; i < m_size; ++i) {
            m_array[i] = o.m_array[i];
        }
        cout << "Copy assignment operator" << endl;
        return *this;
    }

    // move assignment operator
    MyContainer &operator=(MyContainer &&o)
    {
        delete[] m_array;
        m_array = o.m_array;
        m_size = o.m_size;
        o.m_array = nullptr;
        o.m_size = 0;
        cout << "Move assignment operator" << endl;
        return *this;
    }

private:
    Data *m_array;
    unsigned int m_size;
};

void foo(MyContainer x) {}

MyContainer bar()
{
    MyContainer temp{3};
    cout << "In bar" << endl;
    return temp;
}

int main()
{
    MyContainer c{3}; // constructor
    MyContainer d{3}; // constructor
    MyContainer e{d}; // copy constructor
    c = d;            // copy assignment operator
    foo(e);           // copy constructor
    cout << "============================================" << endl;
    c = bar(); // copy assignment operator
    cout << "============================================" << endl;
    MyContainer f{bar()}; // copy constructor
    cout << "============================================" << endl;
    std::vector<int> k{1, 2, 3, 4, 5};
    std::vector<int> l;
    l = std::move(k); // std::move "trasforma" k in R-value reference
}
