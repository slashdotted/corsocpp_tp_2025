#include <iostream>
#include <map>
#include <string>

int main() {
    using namespace std;
    // Initializing a map with some values
    map<string,double> values{{"y", 3.5},{"z", 9.0}};
    for(const pair<string,double>& p : values) {
        cout << "Key: " <<p.first << "Value: " << p.second <<'\n';
    }
    // Assigning new keys to values
    values["pi"] = 3.14;
    values["x"] = 1.23;
    values["pi"] = 3.1415;

    if (values["b"]) { // Beware: b is not in the map, it will be created
    }

    // Checking if a key exists
    if (values.count("b")) {
        cout << "b is in the map " << values["b"] << '\n';
    }

    // Erasing a key
    values.erase("b"); // remove b from the map


}
