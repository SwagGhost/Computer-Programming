#include <iostream>
#include <string>

using namespace std;

int main()
{
    string first_name,last_name;
    int age;
    double height;
    
   cout << endl
   << "Please enter your first and last name, age and height." << "\n" << endl
    << "First name: ";
    cin >> first_name;
    
    cout << "Last name: ";
    cin >> last_name;
    
    //a = age;
    cout << "Age: ";
    cin >> age;
    
    //b = height;
    cout << "Height (in meters): ";
    cin >> height;

cout << endl
<<"\nHello, "<<first_name<<"" << endl
<< "\nWelcome to Computer Programming. You entered the following information:"
<< "\nFull name: "<<first_name<<" "<<last_name<<""
<< "\nAge: "<<age<<" years"
<< "\nHeight: "<<height<<" m" << endl
<< "\nWe hope you will enjoy the course!" << "\n" << endl;
    
    return 0;
}
