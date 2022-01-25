#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

constexpr double DefaultBalance = 0.00;

struct Account
{
    string acc_name;
    char acc_type;
    double balance = DefaultBalance;
};

class Bank
{
    public:
        void create_acc(int, string, char);
        void remove_acc(int, string);
        void transaction(int, string, double);
        void print_records();
    private:
        vector <Account> BankAccounts;
        vector <char> ErrorMessages;
};

void Bank::create_acc(int line, string separate_line, char yn)
{
    Account save;
    save.acc_name = separate_line;
    save.acc_type = yn;
    for (int i = 0; i < BankAccounts.size(); i++)
    {
        if (BankAccounts[i].acc_name != save.acc_name)
        {
            BankAccounts.push_back(save);
        }
        
        else
        {
            ErrorMessages.push_back(line);
            ErrorMessages.push_back('a');
        }
    }
}

void Bank::remove_acc(int line, string name)
{
    for (int j = 0; j < BankAccounts.size(); j++)
    {
        if (BankAccounts[j].acc_name != name)
        {
            ErrorMessages.push_back(line);
            ErrorMessages.push_back('b');
        }
        
        else if (BankAccounts[j].balance >= DefaultBalance)
        {
            BankAccounts.erase(BankAccounts.begin() + j - 1);
        }
        
        else
        {
            ErrorMessages.push_back(line);
            ErrorMessages.push_back('c');
        }
    }
}

void Bank::transaction(int line, string name, double money)
{
    for (int k = 0; k < BankAccounts.size(); k ++)
    {
        if (BankAccounts[k].acc_name != name)
        {
            ErrorMessages.push_back(line);
            ErrorMessages.push_back('b');
        }
        
        else if (BankAccounts[k].acc_type == 'y')
        {
            BankAccounts[k].balance = BankAccounts[k].balance + money;
        }
        
        else if (BankAccounts[k].balance + money >= DefaultBalance)
        {
            BankAccounts[k].balance = BankAccounts[k].balance + money;
        }
        
        else
        {
            ErrorMessages.push_back(line);
            ErrorMessages.push_back('d');
        }
    }
}

void Bank::print_records()
{
    for (int l = 0; l < ErrorMessages.size(); l + 2)
    {
        if (ErrorMessages[l + 1] == 'a')
        {
            cerr << "error on line " << ErrorMessages[l] << ": account already exists";
        }
        
        else if (ErrorMessages[l + 1] == 'b')
        {
            cerr << "error on line " << ErrorMessages[l] << ": account does not exist";
        }
        
        else if (ErrorMessages[l + 1] == 'c')
        {
            cerr << "error on line " << ErrorMessages[l] << ": account holds negative balance";
        }
        
        else
        {
            cerr << "error on line " << ErrorMessages[l] << ": account cannot hold negative balance";
        }
    }
    cout << "\n" << endl;
    for (int m = 0; m < BankAccounts.size(); m++)
    {
        if (BankAccounts[m].balance >= DefaultBalance)
        {
            cout << BankAccounts[m].acc_name << " owns " << BankAccounts[m].balance << "euros";
        }
        
        else
        {
            cout << BankAccounts[m].acc_name << " owes " << BankAccounts[m].balance << "euros";
        }
    }
    cout << endl;
}

int main()
{
    int line = 0;
    Bank use_function;
    string input;
    char action;
    string separate_line;
    string name;
    char yn;
    double money;
    while (cin)
    {
        line++;
        if (cin.eof())
        {
            use_function.print_records();
            break;
        }
        
        getline(cin, input);
        stringstream separate(input);
        separate >> action >> separate_line;
        if (action == 'r')
        {
            use_function.remove_acc(line, separate_line);
        }
        
        else
        {
            stringstream separate(separate_line);
            
            if (action == 'c')
            {
                separate >> name >> yn;
                use_function.create_acc(line, name, yn);
            }
            
            else
            {
                separate >> name >> money;
                use_function.transaction(line, name, money);
            }
        }
    }
    
    return 0;
}