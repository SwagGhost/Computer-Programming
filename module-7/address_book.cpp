#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    string room;
};

class AddressBook {
    private:
        int size;
        Person *Book;
    public:
        AddressBook() {
            size = 0;
            Book = new Person [1];
        }
        
        ~AddressBook() {
            delete[] Book;
        }
        
        bool check(string name) {
            for (int i = 0; i < size; i++) {
                if (Book[i].name == name) {
                    return false;
                }
            }
            return true;
        }
        
        bool check2(int index, string room) {
            if (Book[index].room != room) {
                return true;
            }
            return false;
        }
        
        void add(string name, string room) {
            Person save = {name, room};
            size++;
            Person *temp = new Person[size];
            temp[size - 1] = save;
            for (int i = 0; i < size - 1; i++) {
                temp[i] = Book[i];
            }
            delete[] Book;
            Book = temp;
        }
        
        void move(string name, string room, int index) {
            Person move = {name, room};
            Book[index] = move;
        }
        
        void removePerson(int index) {
            size--;
            Person *temp = new Person[size];
            for (int i = 0; i < index; i++) {
                temp[i] = Book[i];
            }
            for (int j = index; j < size; j++) {
                temp[j] = Book[j+1];
            }
            delete[] Book;
            Book = temp;
        }
        
        int find(string name) {
            for (int i = 0; i < size; i++) {
                if (Book[i].name == name) {
                    return i;
                }
            }
        }
        
        void list(int index) {
            cout << Book[index].name << " is in room " << Book[index].room << endl;
        }
        
        void clear() {
            size = 0;
            Book[1];
        }
        
        int length() {
            return size;
        }
        
        void bubbleSort() {
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (Book[j].name > Book[j + 1].name) {
                        Person temp2 = Book[j];
                        Book[j] = Book[j + 1];
                        Book[j + 1] = temp2;
                    }
                }
            }
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (Book[j].room > Book[j + 1].room) {
                        Person temp = Book[j];
                        Book[j] = Book[j + 1];
                        Book[j + 1] = temp;
                    }
                }
            }
        }
};

bool checkName(string name) {
    if (! (name.at(0) >= 'A' && name.at(0) <= 'Z')) {
        return false;
    }
    for (int i = 1; i < name.size(); i++) {
        if (! isalpha(name.at(i))) {
            return false;
        }
    }
    return true;
}

bool checkRoom(string room) {
    if (room.size() == 4 && room.at(0) >= 'A' && room.at(0) <= 'Z' &&
    isdigit(room.at(1)) && isdigit(room.at(2)) && isdigit(room.at(3))) {
        return true;
    }
    return false;
}

int main() {
    AddressBook input;
    string name, room;
    string action;
    
    while (cin) {
        cout << "> ";
        cin >> action;
        if (action == "add") {
            cin >> name >> room;
            if (checkName(name) == false && checkRoom(room) == true) {
                cerr << "Error: Invalid name.\n";
            }
            else if (checkName(name) == true && checkRoom(room) == false) {
                cerr << "Error: Room does not exist.\n";
            }
            else if (checkName(name) == false && checkRoom(room) == false) {
                cerr << "Error: Invalid name.\nError: Room does not exist.\n";
            }
            else {
                if (input.check(name) == true) {
                    input.add(name, room);
                }
                else {
                    cerr << "Error: Entry already exists.\n";
                }
            }
        }
        else if (action == "move") {
            cin >> name >> room;
            if (checkName(name) == false && checkRoom(room) == true) {
                cerr << "Error: Invalid name.\n";
            }
            else if (checkName(name) == true && checkRoom(room) == false) {
                cerr << "Error: Room does not exist.\n";
            }
            else if (checkName(name) == false && checkRoom(room) == false) {
                cerr << "Error: Invalid name.\nError: Room does not exist.\n";
            }
            
            else {
                if (input.check(name) == true) {
                    cerr << "Error: Entry does not exist.\n";
                }
                else {
                    if (input.check2(input.find(name), room) == true) {
                        input.move(name, room, input.find(name));
                    }
                    
                    else {
                        cerr << "Error: Person is already in room " << room << ".\n";
                    }
                }
            }
        }
        else if (action == "remove") {
            cin >> name;
            if (checkName(name) == false) {
                cerr << "Error: Invalid name.\n";
            }
            else {
                if (input.check(name) == false) {
                    input.removePerson(input.find(name));
                }
                else {
                    cerr << "Error: Entry does not exist.\n";
                }
            }
        }
        else if (action == "find") {
            cin >> name;
            if (checkName(name) == false) {
                cerr << "Error: Invalid name.\n";
            }
            else {
                if (input.check(name) == false) {
                    input.list(input.find(name));
                }
                else {
                    cerr << "Error: Entry does not exist.\n";
                }
            }
        }
        else if (action == "list") {
            input.bubbleSort();
            for (int k = 0; k < input.length(); k++) {
                input.list(k);
            }
        }
        else if (action == "clear") {
            input.clear();
        }
        else if (action == "exit") {
            break;
        }
        else {
            cerr << "Error: Invalid action.\n";
        }
    }
    
    return 0;
}
