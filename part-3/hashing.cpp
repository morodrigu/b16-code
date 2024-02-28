#include <iostream>
#include <string>
#include <cstdint>      // For uint32_t


using namespace std;

// Hash function
uint32_t hash_function(const std::string& str, const uint32_t m) {
    // Initialising result
    uint32_t result = 0;

    // Initialising power
    uint32_t power = 1;

    // Looping over each value in the string
    for (size_t i = 0; i < str.length(); ++i) {
        uint32_t l_mod_m = ((str[i] % m)*(power)) % m;
        result = (result + l_mod_m) % m;
        power = (power * 256) % m;
    }

    // Returning the result (the hash value)
    return result;
}



int main() {
    uint32_t m = 255;

    string str = "ciao";
    uint32_t h = hash_function(str, m);
    cout << str << endl;
    cout << h << endl;

    str = "oiac";
    h = hash_function(str, m);
    cout << str << endl;
    cout << h << endl;


    return 0;
}
