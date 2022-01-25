#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iteration;
    int term;
    
    cout << "Please enter the number of iterations: ";
    cin >> iteration;
    
    vector <int> sequence;
    for (int i = 0; i < iteration; i++)
    {
        sequence.push_back( 2 * i - 3 );
    }
    sequence.push_back( 2 * iteration - 3 );
    
    cout << "Which term would you like to know: ";
    cin >> term;
    
    cout << "The value of term " << term << " is " << sequence[term] << endl;
    
    cout << "The entire sequence up to term " << iteration << " is: ";
    for (int j = 1; j < iteration; j++)
    {
        cout << sequence[j] << " ";
        
    }
    cout << sequence[iteration] << "\n" << endl;
    
    return 0;
}