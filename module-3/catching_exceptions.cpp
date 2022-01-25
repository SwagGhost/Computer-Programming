#include <iostream>

using namespace std;

class Bad_input { };

int main ( )
{
    int integer;
    
    cout << "Please enter integers only\n";
    
    try
    {
        while ( cin >> integer )
        {
            cout << integer << " OK\n";
        }
        
        throw Bad_input { };
    }
    
    catch ( Bad_input )
    {
        cerr << "error: input mismatch\n" << endl;
    }
    
    return 0;
}
