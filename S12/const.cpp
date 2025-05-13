struct Base
{
    void foo() const {}
    void bar() {}
};

int main()
{
    const Base *b{new Base};
    b->foo(); // Ok
    // b->bar(); // Error! Not const!
    // Base* bc = static_cast<Base*>(b); // Not permitted
    // Base* bc = reintepret_cast<Base*>(b); // Not permitted
    // Base* bc = dynamic_cast<Base*>(b); // Not permitted
    // Base ncb{const_cast<Base>(*b)}; // Converting values is not allowed
    Base *bc = const_cast<Base *>(b); // Ok
    bc->bar();                        // Ok
    delete b;
}
