#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Bad_input {};
class No_input {};
class No_second_smallest {};

int main ()
{
    try
    {
        vector <int> integers;
        char terminate_input;
        
        cout << "Enter the number in random order: ";
        
        for (int integer; cin >> integer;)
        {
            integers.push_back(integer);
        } 
        
        if (terminate_input = getchar() != EOF)
        {
            throw Bad_input {};
        }
        
        /* The input will be terminated after pressing 'CTRL' and 'D' together
           if there is invalid input.
           The input will be terminated after pressing two times 'CTRL' and 'D'
           together if there is no input.
           The input will be terminated after pressing three times
           'CTRL' and 'D' together if there is valid input (also if the input
           is just one integer or one integer entered multiple times). */
        
        if (integers.size() == 0)
        {
            throw No_input {};
        }
        
        sort (integers.begin(), integers.end());
        
        integers.erase (unique(integers.begin(), integers.end()), integers.end());
        
        if (integers[0] != integers.back())
        {
            cout << "\nThe second smallest number is " << integers[1] << "\n" << endl;
        }
        
        else if (integers[0] == integers.back())
        {
            throw No_second_smallest {};
        }
    }
    
    catch (Bad_input)
    {
        cerr << "\nError: Invalid input.\n" << endl;
    }
    
    catch (No_input)
    {
        cerr << "\nError: No input.\n" << endl;
    }
    
    catch (No_second_smallest)
    {
        cerr << "\nerror: no second smallest\n" << endl;
    }
}
