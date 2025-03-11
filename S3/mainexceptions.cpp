#include <iostream>
#include <vector>

void foo() noexcept {
    throw "NULLPOINTERBLABLA";
}

int main() {
    using namespace std;
    vector<int> myvector{8,6,7,1};
    try {
        cout << "element: " << myvector.at(40000) << '\n';
    } catch(const out_of_range& e) {
        cout << "Exception:" << e.what() << '\n';
    }

    //cout << "element: " << myvector.at(40000) << '\n';

    try {
        //int* x{new int};
        int x;
        foo();
        //delete x;
    } catch(const char* msg) {
        //
    } catch(int x) {

    } catch(...) { // default
        cout << "Exception";
        throw; // rethrow existing exception;
    }

    try {
        throw 13;
    } catch (int i) {

    }


    //cout << "element: " << myvector[40000] << '\n';
}
