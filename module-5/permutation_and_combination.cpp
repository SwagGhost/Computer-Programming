#include <iostream>

using namespace std;

class IntegerError {};
class InvalidInput {};
class NotPC {};

int factorial(int abc);

void permutation(int a, int b)
{
    int factorial_a = factorial(a);
    int c = a - b;
    int factorial_ab = factorial(c);
    int P = factorial_a / factorial_ab;
    cout << "the permutation of " << a << " and " << b << " = " << P << "\n" << endl;
}

void combination(int a, int b)
{
    int factorial_a = factorial(a);
    int factorial_b = factorial(b);
    int c = a - b;
    int factorial_ab = factorial(c);
    int C = factorial_a / factorial_ab / factorial_b;
    cout << "the combination of " << a << " and " << b << " = " << C << "\n" << endl;
}

int factorial(int abc)
{
    if (abc > 1)
    {
        return abc * factorial(abc - 1);
    }
    else
    {
        return 1;
    }
}

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    try
    {
        if (! cin || ! (a >= 0 && b >= 0))
        {
            throw IntegerError {};
        }
        
        else if (a < b)
        {
            throw InvalidInput {};
        }
    }
    
    catch(IntegerError)
    {
        cerr << "Error: Input is not an integer between zero and nine.\n" << endl;
        return 1;
    }
    
    catch(InvalidInput)
    {
        cerr << "Error: The first integer can not be smaller than the second integer.\n" << endl;
        return 2;
    }
    
    char pc;
    cout << "Enter 'p' for permutation or 'c' for combination: ";
    cin >> pc;
    try
    {
        if (pc == 'p')
        {
            permutation(a, b);
        }
        
        else if (pc == 'c')
        {
            combination(a, b);
        }
        
        else
        {
            throw NotPC {};
        }
    }
    
    catch(NotPC)
    {
        cerr << "Error: Input is not 'p' or 'c'.\n" << endl;
        return 3;
    }
    
    return 0;
}