#include <iostream>

using namespace std;

class Invalid_input {};
class Letter_expected {};
class Number_expected {};

int main() {
    try {
        char a, b, c, x, y, z;
        
        cout << "Please enter the VUnet ID: ";
        cin >> a >> b >> c >> x >> y >> z;
        
        if (! cin) {
            throw Invalid_input {};
        }
        
        if (isalpha(a) && isalpha(b) && isalpha(c)) {
            if (isdigit(x) && isdigit(y) && isdigit(z)) {
                cout << "The VUnet ID " << a << b << c << x << y << z << " is correct.";
            }
            
            else if (isalpha(x) && isdigit(y) && isdigit(z)) {
                throw Number_expected {};
            }
            
            else if (isdigit(x) && isalpha(y) && isdigit(z)) {
                throw Number_expected {};
            }
            
            else if (isdigit(x) && isdigit(y) && isalpha(z)) {
                throw Number_expected {};
            }
            
            else if (isalpha(x) && isalpha(y) && isdigit(z)) {
                throw Number_expected {};
            }
            
            else if (isalpha(x) && isdigit(y) && isalpha(z)) {
                throw Number_expected {};
            }
            
            else if (isdigit(x) && isalpha(y) && isalpha(z)) {
                throw Number_expected {};
            }
            
            else {
                throw Invalid_input {};
            } 
        }
        
        else if (isdigit(a) || isdigit(b) || isdigit(c)) {
            if ((isalpha(a) || isdigit(a)) && (isalpha(b) || isdigit(b))) {
                if ((isalpha(c) || isdigit(c)) && (isalpha(x) || isdigit(x))) {
                    if (isalpha(z) || isdigit(z) && (isalpha(y) || isdigit(y))) {
                        throw Letter_expected {};
                    }
                }
            }
        }
        
        else {
            throw Invalid_input {};
        }
    }
    
    catch(Invalid_input) {
        cerr << "Error: Invalid input.";
    }
    
    catch(Letter_expected) {
        cerr << "error: letter expected";
    }
    
    catch(Number_expected) {
        cerr << "error: number expected";
    }
    
    cout << "\n" << endl;
    
    return 0;
}
