struct Distance
{
    long double meters;
    Distance(long double v)
        : meters{v}
    {}

    static Distance from_miles(long double v) { return Distance(v * 1600); }
};

Distance operator""_miles(long double v)
{
    return Distance::from_miles(v);
}

Distance operator""_miles(unsigned long long v)
{
    return Distance::from_miles(v);
}

Distance operator""_mi(long double v)
{
    return Distance::from_miles(v);
}

Distance operator""_m(long double v)
{
    return Distance(v);
}

Distance operator""_km(long double v)
{
    return Distance(v * 1000);
}

/*double operator ""_km(long double v) {
    return v*1000;
}*/

int main()
{
    Distance d1{1000};
    Distance d2{1500};
    Distance d3{1.7 * 1600};
    Distance d4{Distance::from_miles(1.5)};
    Distance d5{1.5_miles};
    Distance d6{6.7_km};
    Distance d7{7_miles}; // calls unsigned long long
}
