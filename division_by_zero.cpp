#include <iostream>
#include <cmath>

using namespace std;

class Division_by_zero { };
class Bad_input { };

int main ( )
{
    try    
    {
        double a;
        double b;
        double c;
        
        cout << "ax^2 + bx + c = 0\n" << "Please enter the values of a, b, and c respectively: ";
        cin >> a >> b >> c;
        
        double d = pow ( b, 2.0 ) - 4 * a * c;
        double x1 = ( -b + sqrt ( d ) ) / ( 2 * a );
        double x2 = ( -b - sqrt ( d ) ) / ( 2 * a );

        if ( x1 != x2 && a != 0 )
        {
            cout << "There are 2 solutions.\n";
                
            if ( x1 == -0 )
            {
                cout << "The solutions are: x = 0 or x = " << x2 << "\n" << endl;
            }
            
            else if ( x2 == -0 )
            {
                cout << "The solutions are: x = " << x1 << " or x = 0\n" << endl;
            }
            
            else
            {
                cout << "The solutions are: x = " <<x1<< " or x = " << x2 << "\n" << endl;
            }
        }
        
        else if ( x1 == x2 && a != 0 )
        {
            cout << "There is 1 solution.\n";
            
            if ( x1 == -0 )
            {
                cout << "The solutions are: x = 0\n" << endl;
            }
        
            else
            {
                cout << "The solutions are: x = " << x1 << "\n" << endl;
            }
        }
        
        else if ( cin )
        {
            throw Division_by_zero { };
        }
        
        else if ( ! cin )
        {
            throw Bad_input { };
        }
    }
    
    catch ( Division_by_zero )
    {
        cerr << "error: division by 0\n" << endl;
    }
    
    catch ( Bad_input )
    {
        cerr << "error: invalid input\n" << endl;
    }

    return 0;
}