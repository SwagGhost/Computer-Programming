#include <iostream>

using namespace std;

int main()
{
    double a;
    char op;
    double b;
    
    while ( cin >> a >> op >> b )
    {
        switch( op )
        {
            case '+':
                cout << "" << a << " " << op << " " << b << " = "
                << a + b << "\n" << endl;
                break;
        
            case '-':
                cout << "" << a << " " << op << " " << b << " = "
                << a - b << "\n" << endl;
                break;
        
            case '*':
                cout << "" << a << " " << op << " " << b << " = "
                << a * b << "\n" << endl;
                break;
        
            case '/':
                cout << "" << a << " " << op << " " << b << " = "
                << a / b << "\n" << endl;
                break;
        
            default:
                cout << "" << endl;
    }
}

    return 0;
}