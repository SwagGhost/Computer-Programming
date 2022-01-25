#include <iostream>

using namespace std;

int main()
{
    int e;
    int c;
    
    cout << "Enter the amount of exclamation marks to be printed: ";
    cin >> e;
    
    for ( int i = 0; i < e; i++ )
    {
        cout << "! ";
    }
    
    cout << "\n" << endl;
    
    cout << "Enter the amount of commas to be printed: ";
    cin >> c;
    
    for ( int j = 0; j < c; j++ )
    {
        cout << ", ";
    }
    
    cout << "\n" << endl;
    
    return 0;
}