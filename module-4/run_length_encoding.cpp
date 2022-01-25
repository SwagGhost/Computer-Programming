#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Invalid_input {};

int main()
{
    string data;
    vector <string> compressed_data;
    char letter;
    int count;
    
    cout << "Enter the data to be compressed: ";
    cin >> data;
    
    try
    {
        for (int i = 0; i < data.size(); i++)
        {
            letter = data.at(i);
            if (letter >= 'a' && letter <= 'z')
            {
                count = 1;
                while (data[i] == data[i+1])
                {
                    count++, i++;
                }
                compressed_data.push_back(to_string(count) + data[i]);
            }
            
            else
            {
                throw Invalid_input {};
            }
        }
        
        cout << "The compressed data is: ";
        for (int j = 0; j < compressed_data.size(); j++)
        {
            cout << compressed_data[j];
        }
        cout << "\n" << endl;
    }
    
    catch(Invalid_input)
    {
        cerr << "Error: Invalid input.\n" << endl;
    }
    
    return 0;
}
