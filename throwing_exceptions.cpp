#include <iostream>

using namespace std;

class Bad_input { };

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
            throw Bad_input { };
        }
    
    return 0;
}