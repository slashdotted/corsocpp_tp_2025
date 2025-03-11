#pragma once
#include <string>
#include <iostream>

class Fraction {
public: // by default using struct (private: is the default using class)
    //void print();
    Fraction(int numerator = 0, int denominator = 1);
    //Fraction();
    //Fraction(int numerator);
    int numerator() const;
    void numerator(int v);
    int denominator() const;
    void denominator(int v);
    // inline by default
    void print() const {
        std::cout << numerator() << "/" << denominator() << std::endl;
    }
private: // or protected:
    int n;
    int d;
};


