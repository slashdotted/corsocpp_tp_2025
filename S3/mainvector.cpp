#include <iostream>
#include <vector>

int main() {
    using namespace std;
    vector<int> myvector{8,6,7,1};

    myvector.push_back(8);
    myvector.push_back(6);
    myvector.push_back(7);
    myvector.push_back(1);

    cout << "First element: " << myvector.at(0) << '\n';
    cout << "First element: " << myvector[0] << '\n';

    cout << "Size:" << myvector.size() << '\n';

    auto start = myvector.begin(); // start of the vector
    cout << "First element:" << *start << '\n';
    auto end = myvector.end(); // past the end of the vector
    for(;start != end;++start) {
        cout << "Element: " << *start << '\n';
    }
    myvector.erase(myvector.begin()+1); // Remove 2nd element

    for (int& i : myvector) {
        ++i;
    }

    for (const int& i : myvector) {
        cout << i << '\n';
    }

    int value{9};
    myvector.push_back(value);

    vector<double*> data;
    data.push_back(new double{3.14});
    data.push_back(new double{1.23});
    for (double* p : data) {
        delete p;
    }
    data.clear();
}
