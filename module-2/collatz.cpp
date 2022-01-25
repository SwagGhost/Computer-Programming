#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter an even number.\n";
    cout << "Number: ";
    cin >> n;
    
    cout << "\n" << n << " ";
    
    
    while ( n != 1 )
    {
        if ( n % 2 )
            n = 3 * n + 1;
        else
            n = n / 2;
        
        cout << n << " ";
    }
    cout << "\n" << endl;
    
    return 0;
}
