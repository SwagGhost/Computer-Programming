#include <iostream>

using namespace std;

int main ( )
{
    int integer;
    
    cout << "Please enter integers only\n";
    
        while ( cin >> integer )
        {
            cout << integer << " OK\n";
        }
        
        if ( ! cin )
        {
            cout << "Error: Invalid input, ending program\n" << endl;
        }
    
    return 0;
}
