#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a;
    double b;
    double c;
    
    cout << "ax^2 + bx + c = 0\n" << "Enter values for a, b and c.\n" << "a: ";
    cin >> a;
    
    cout << "b: ";
    cin >> b;
    
    cout << "c: ";
    cin >> c;
    
    double q = pow( b, 2.0 ) - 4 * a * c;
    double x1 = ( -b - sqrt( q ) ) / 2 * a;
    double x2 = ( -b + sqrt( q ) ) / 2 * a;
    
    if ( a != 0 )
    {
        if( x1 != x2 )
        {
            if( x1 == -0 )
                cout << "Solutions: x = 0 or x = " << x2 << "\n" << endl;
                
            else if ( x2 == -0 )
                cout << "Solutions: x = " << x1 << " or x = 0\n" << endl;
                
            else
                cout << "Solutions: x = " <<x1<< " or x = " << x2 << "\n" << endl;
        }
    
        else
        {
            if( x1 == -0 )
                cout << "Solution: x = 0" << endl;
                
            else
                cout << "Solution: x = " << x1 << "" << endl;
        }
    }
    return 0;
}
