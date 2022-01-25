#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int length,width;
    cout << "Please enter the length and width of a rectangle." << "\n";
    
    cout << "Length: ";
    cin >> length;
    
    cout << "Width: ";
    cin >> width;
    
    int perimeter;
    perimeter = length * 2 + width *2;
    int area;
    area = length * width;
    float diagonal;
    diagonal = sqrt (length * length + width * width);
    
    cout << endl;
    cout << "The perimeter is "<<perimeter<<", the area is "<<area<<", the diagonal is "<<diagonal<<"." << "\n" << endl;
    
    return 0;
}