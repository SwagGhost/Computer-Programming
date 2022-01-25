#include <iostream>
#include <vector>

using namespace std;

class Invalid_input {};
class Empty_vector {};
class Too_less_elements {};
class Too_many_elements {};

int main()
{
    try
    {
        int size;
        int sort;
        
        cout << "Please enter the number of elements: ";
        cin >> temp;
        
        if (! cin || size <= 0 || cin.get() == ' ')
        {
            throw Invalid_input {};
        }
        
        vector <int> list;
        
        cout << "Enter the list to be sorted: ";
        
        for (int element; cin >> element;)
        {
            list.push_back(element);
            
            if (cin.get() == '\n')
            {
                if (list.size() == 0)
                {
                    throw Empty_vector {};
                }
                
                if (list.size() < size)
                {
                    throw Too_less_elements {};
                }
                
                if (list.size() > size)
                {
                    throw Too_many_elements {};
                }
                
                for (int i = 0; i < size - 1; i++)
                {
                    for (int j = 0; j < size - i - 1; j++)
                    {
                        if (list[j] > list[j+1])
                        {
                            temp = list[j];
                            list[j] = list[j+1];
                            list[j+1] = temp;
                        }
                    }
                }
                
                cout << "The sorted list is: ";
                
                for (int k = 0; k < size; k++)
                {
                    cout << list[k] << " ";
                }
                
                cout << "\n" << endl;
                
                break;
            }
        }
        
        if (! cin)
        {
            throw Invalid_input {};
        }
    }
    
    catch(Invalid_input)
    {
        cerr << "Error: Invalid input.\n" << endl;
    }
    
    catch(Empty_vector)
    {
        cerr << "Error: No list entered.\n" << endl;
    }
    
    catch(Too_less_elements)
    {
        cerr << "Error: Too less numbers entered.\n" << endl;
    }
    
    catch(Too_many_elements)
    {
        cerr << "Error: Too many numbers entered.\n" << endl;
    }
    
    return 0;
}