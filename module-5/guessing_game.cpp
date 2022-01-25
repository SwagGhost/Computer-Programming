#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class InvalidInput {};
class AmountError {};
class PatternError {};

void GuessSequence(string Sequence);

void CreateSequence(int AmountDifferentChars, int PatternLength, string EmptySequence)
{
    srand(time(0));
    char GenerateCharacters;
    int NeededCharacters = PatternLength - AmountDifferentChars;
    int AddCharacters;
    string Sequence = "";
    
    if (AmountDifferentChars == 0)
    {
        GenerateCharacters = rand() % 25 + 65;
        for (int i = 0; i < PatternLength; i++)
        {
            Sequence += GenerateCharacters;
        }
    }
    else
    {
        for (int i = 0; i < PatternLength; i++)
        {
            GenerateCharacters = rand() % AmountDifferentChars + 65;
            Sequence += GenerateCharacters;
        }
    }
    EmptySequence = Sequence;
    GuessSequence(Sequence);
}

void GuessSequence(string Sequence)
{
    int right;
    int guess = 1;
    string UserGuess;
    char CheckUserGuess;
    
    cout << "Enter your guess: ";
    cin >> UserGuess;
    
    while (Sequence != UserGuess)
    {
        right = 0;
        for (int k = 0; k < Sequence.length(); k++)
        {
            if (Sequence[k] == UserGuess[k])
            {
                right++, k++;
            }
        }
        for (int CheckChar = 0; CheckChar < Sequence.length(); CheckChar++)
        {
            CheckUserGuess = UserGuess.at(CheckChar);
            if (! (CheckUserGuess >= 'A' && CheckUserGuess <= 'Z'))
            {
                cout << "error: invalid guess\n";
                break;
            }
            else if (! cin || Sequence.length() != UserGuess.length())
            {
                cout << "error: invalid guess\n";
                break;
            }
            else if (right == 1)
            {
                cout << "You guessed 1 character correctly\n";
                guess++;
                break;
            }
            else
            {
                cout << "You guessed " << right<< " characters correctly\n";
                guess++;
                break;
            }
        }
        cout << "Enter your guess: ";
        cin >> UserGuess;
    }
    
    if (Sequence == UserGuess)
    {
        if (Sequence.length() == 1)
        {
            cout << "You guessed 1 character correctly\n" << endl;
        }
        else
        {
            cout << "You guessed " << Sequence.length() << " characters correctly\n" << endl;
        }
        if (guess == 1)
        {
            cout << "You guessed the pattern in 1 guess\n" << endl;
        }
        else
        {
            cout << "You guessed the pattern in " << guess << " guesses\n" << endl;
        }
    }
}

int main()
{
    int AmountDifferentChars, PatternLength;
    string EmptySequence = "";
    
    cout << "Enter the amount of different characters: ";
    cin >> AmountDifferentChars;
    
    try
    {
        if(! cin)
        {
            throw InvalidInput {};
        }
        else if (AmountDifferentChars < 0 || AmountDifferentChars > 26)
        {
            throw AmountError {};
        }
        
        cout << "Enter the pattern length: ";
        cin >> PatternLength;
        
        if (! cin)
        {
            throw InvalidInput {};
        }
        else if (PatternLength <= 0)
        {
            throw PatternError {};
        }
    }
    
    catch(InvalidInput)
    {
        cerr << "Error: Invalid input.\n" << endl;
        return 1;
    }
    catch(AmountError)
    {
        cerr << "Error: This amount of different characters is invalid.\n" << endl;
        return 2;
    }
    catch(PatternError)
    {
        cerr << "Error: This pattern length is invalid.\n" << endl;
        return 3;
    }
    
    CreateSequence(AmountDifferentChars, PatternLength, EmptySequence);
    void GuessSequence(string Sequence);
    
    return 0;
}