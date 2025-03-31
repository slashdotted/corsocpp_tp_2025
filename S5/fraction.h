#pragma once
#include <string>
#include <iostream>

class Fraction {
public: // by default using struct (private: is the default using class)
    //void print();
    Fraction(); // Just to show how to use delegating constructors
    Fraction(int numerator, int denominator = 1);
    //Fraction();
    //Fraction(int numerator);
    int numerator() const;
    void numerator(int v);
    int denominator() const;
    void denominator(int v);

    operator double() const { return (double) n / d; }

    //void increaseBy(const Fraction& f);
    Fraction& operator+=(const Fraction& f);
    //Fraction operator+(const Fraction& f);

    // inline by default
    void print() const { std::cout << numerator() << "/" << denominator() << std::endl; }

    // overload the prefix operator ++f
    Fraction &operator++()
    {
        // return the alredy incremented value
        return *this += 1;
    }

    // overload the postfix operator f++
    Fraction operator++(int)
    {
        Fraction temp{*this};
        *this += 1;
        return temp;
    }

private: // or protected:
    int n;
    int d;
};


