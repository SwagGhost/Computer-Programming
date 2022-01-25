#include <iostream>

using namespace std;

const int minimum_donation = 50;

int main()
{
    float money;
    cout << "How much do you want to donate to charity: the thirsty toads in the Sahara?" << "\n" << endl
    << "Enter the amount you want to donate: ";
    cin >> money;
    
    while ( money < minimum_donation )
    {
        cout << "Enter the amount you want to donate: ";
        cin >> money;
    }
    
    cout << "Thank you for your contribution of " << money << " euro." << "\n" << endl;

    return 0;
}
