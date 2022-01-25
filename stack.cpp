#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Stack {
    private:
        vector <int> elements;
    public:
        int end();
        bool isEmpty();
        int peek();
        int pop();
        void push(int);
};

int Stack::end() {
    for (int i = 0; i < elements.size(); i++) {
        cout << elements[i] << " ";
    }
}

bool Stack::isEmpty() {
    if (elements.size() == 0) {
        return false;
    }
    
    else {
        return true;
    }
}

int Stack::peek() {
    if (isEmpty() == false) {
        cerr << "error: stack empty\n";
    }
    
    else {
        cout << elements.back() << endl;
    }
}

int Stack::pop() {
    if (isEmpty() == false) {
        cerr << "error: stack empty\n";
    }
    
    else {
        cout << elements.back() << endl;
        int lastElement = elements.size() - 1;
        elements.erase(elements.begin() + lastElement);
    }
}

void Stack::push(int x) {
    elements.push_back(x);
}

int main() {
    Stack s;
    while (cin) {
        string stack;
        int x;
        cout << "> ";
        stringstream check_input;
        check_input.clear();
        check_input.str("");
        string input = "";
        
        while (true) {
            if (! getline(cin, input)) {
                return 1;
            }
            
            check_input.str(input);
            
            if (check_input >> stack) {
                if (check_input >> x) {
                    if (stack == "push") {
                        s.push(x);
                        break;
                    }
                }
                
                else if (stack == "pop") {
                    s.pop();
                    break;
                }
                
                else if (stack == "peek") {
                    s.peek();
                    break;
                }
                
                else if (stack == "end") {
                    s.end();
                    break;
                }
            }
            
            cout << "Error: Invalid input.\n> ";
            
            check_input.clear();
            check_input.str("");
            input.clear();
        }
        
        if (stack == "end") {
            cout << endl;
            break;
        }
    }
    
    return 0;
}