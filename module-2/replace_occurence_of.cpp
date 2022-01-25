#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int divisor;
    int list;
    
    cout << "Enter the divisor: ";
    cin >> divisor;
    
    cout << "Enter the list to be updated: ";
    
    vector <int> updated_list;
    for ( int list; cin >> list; )
    {
        if ( list % divisor )
        {
            updated_list.push_back( list );
        }
        
        else
        {
            updated_list.push_back( list + 1 );
        }
    }
    
    cout << "The updated list is: ";
    for ( int i = 0; i < updated_list.size(); i++)
    {
        cout << updated_list[i] << " ";
    }
    
    cout << "\n" << endl;
    
    return 0;
}
