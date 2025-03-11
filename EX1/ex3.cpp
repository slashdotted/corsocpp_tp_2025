#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    ifstream inf;
    inf.open("mydata");
    char str[11];
    inf.get(str, 10);
    cout << "-" << str << "-" << endl;
    inf.ignore(3);
    char z;
    inf.get(z);
    cout << "-" << z << "-" << endl;
}
