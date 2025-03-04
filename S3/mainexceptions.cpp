#include <iostream>
#include <vector>

int main() {
    using namespace std;
    vector<int> myvector{8,6,7,1};
    try {
        cout << "element: " << myvector.at(40000) << '\n';
    } catch(const out_of_range& e) {
        cout << "Exception:" << e.what() << '\n';
    }

    //cout << "element: " << myvector[40000] << '\n';
}
