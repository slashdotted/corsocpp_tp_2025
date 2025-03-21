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

    //void increaseBy(const Fraction& f);
    Fraction& operator+=(const Fraction& f);
    //Fraction operator+(const Fraction& f);

    // inline by default
    void print() const {
        std::cout << numerator() << "/" << denominator() << std::endl;
    }
private: // or protected:
    int n;
    int d;
};


