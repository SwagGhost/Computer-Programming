#include <iostream>

using namespace std;

class IntRow {
    private:
        int *elements;
        int size;

    public:
        IntRow() // constructor
        {
            size = 0;
            elements = new int[1];
        }
            
        ~IntRow() // destructor
        {
            delete[] elements;
        }
        
        int at(int index) // returns the element at position index
        {
            return elements[index];
        }
        
        void push_back(int value) // adds value to this IntRow
        {
            size++;
            int* temp = new int[size];
            temp[size - 1] = value;
            
            for (int i = 0; i < size - 1;  i++)
            {
                temp[i] = elements[i];
            }
            delete[] elements;
            elements = temp;
        }
        
        int length() // returns the amount of elements in this IntRow
        {
            return size;
        }
};

int main()
{
    IntRow x;
    
    int iteration;
    cout << "Enter the number of iterations: ";
    cin >> iteration;
    
    for (int i = 0; i <= iteration; i++)
    {
        x.push_back(2 * i - 3);
    }
    
    int term;
    cout << "Which term would you like to know: ";
    cin >> term;
    
    cout << "The value of term " << term << " is " << x.at(term) << endl;
    
    if (iteration == 1)
    {
        cout << "The entire sequence up to 1 element is -1";
    }
    
    else if (iteration > 1)
    {
        cout << "The entire sequence up to " << iteration << " elements is: ";
    }
    
    for (int j = 0; j < iteration; j++)
    {
        cout << x.at(j+1) << " ";
    }
    
    cout << "\n" << endl;
    
    return 0;
}