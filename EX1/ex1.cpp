#include <string>
#include <iostream>
#include <limits>
int main() {
    using namespace std;
    const int THISYEAR{2025};
    string yourName;
    int birthYear;
    cout << " What is your name? " << flush;
    //cin >> yourName;
    std::getline (cin, yourName);
    do {
        cout << "What year were you born? " ;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        cin >> birthYear;
    } while (cin.fail());
    cout << "Your name is " << yourName
         << " and you are approximately "
         << (THISYEAR - birthYear)
         << " years old. " << endl;
}


