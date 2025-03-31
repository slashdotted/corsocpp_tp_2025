#include <functional>
#include <iostream>

struct Tommy
{
    Tommy(const std::string &name)
        : m_name{name}
    {}

    void operator()(const std::string &msg)
    {
        std::cout << m_name << " says " << msg << "!";
        m_last = msg;
    }

    void repeat() { std::cout << m_last; }
    void say(const std::string &msg)
    {
        std::cout << m_name << " says " << msg << "!";
        m_last = msg;
    }

private:
    std::string m_last;
    std::string m_name;
};

void foo(Tommy &x)
{
    x.repeat();
    x("Hello moon");
}

std::function<void(const std::string &)> funReturningLambda()
{
    std::string myname{"Alan"};
    std::string suffix{"!"};
    // Warning! Capturing local variables by reference is a big NO NO NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
    return [&](const std::string &m) -> void {
        std::cout << myname << " says: " << m << suffix << std::endl;
    };
}

int main()
{
    /* Tommy t{"John"};
    t.say("Hello world");
    t("Ciao mondo");

    Tommy p{"Paul"};
    p.say("Hello world");
    p("Ciao mondo");

    foo(p);
    */
    /*std::string myname{"Alan"};
    std::string suffix{"!"};
    auto fun = [=](const std::string &m) -> void { std::cout << myname << " says: " << m << suffix << std::endl; };
    myname = "Arianna";
    fun("Me");*/
    auto f = funReturningLambda();
    f("Pippo");

    // double k{3.5};
    auto mylambda = [k = 0](int i) mutable {
        std::cout << "Called: " << ++k;
        return ++i;
    };

    mylambda(3);
}
