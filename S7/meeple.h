#pragma once
#include <string>

struct Meeple
{
    Meeple(const std::string &name)
        : m_name{name}
    {
        ++meeple_counter;
    }

    ~Meeple() { --meeple_counter; }

    Meeple(const Meeple &o)
        : m_name{o.m_name}
    {
        ++meeple_counter;
    }

    static int counter() { return meeple_counter; }

    const std::string &name() const { return m_name; }

private:
    static int meeple_counter;
    std::string m_name;
};
