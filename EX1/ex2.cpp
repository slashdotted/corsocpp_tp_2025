#include <fstream>
#include <iostream>
int main() {
    using namespace std;
    int lucky{7};
    float pi{3.14};
    double e{2.71};
    ofstream outf;
    outf.open("mydata");
    outf << lucky << endl;
    outf << pi << endl;
    outf << e << endl;
    outf << "This is an example" << endl;
    outf.flush();
    outf.close();

    lucky = 0;
    pi = 0;
    e = 0;
    string text;
    ifstream inf;
    inf.open("mydata");
    inf >> lucky;
    inf >> pi;
    inf >> e;
    inf.ignore(1,'\n');
    getline(inf, text);
    inf.close();
    cout << "lucky=" << lucky << ", pi=" << pi
         << ", e=" << e << ", text=" << text << endl;
}
