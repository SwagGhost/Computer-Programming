#include <iostream>

using namespace std;

void pyramid(int line)
{
    int left_space = 24;
    int right_space = 26;
    
    for (int i = 0; i < line; i++)
    {
        
        for (int j = 0; j < left_space; j++)
        {
            cout << " ";
        }
        
        left_space -= 1;
        right_space -= 1;
        
        for (int k = 0; k <= i; k++)
        {
            cout << "*";
        }
        
        for (int l = 1; l <= i; l++)
        {
            cout << "*";
        }
        
        for (int m = 0; m < right_space; m++)
        {
            cout << " ";
        }
        
        cout << endl;
    }
}

int main()
{
    cout << endl;
    int line = 10;
    pyramid(line);
    cout << endl;
    
    return 0;
}
