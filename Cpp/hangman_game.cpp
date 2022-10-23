#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//A simple attractive multiplayer hangman game using object oriented programming
//This is the structure of the game
/*
+---------------------------------+
|             HANG MAN            |
+---------------------------------+
|               |                 |
|               |                 |
|               O                 |
|              /|\                |
|               |                 |
|              / \                |
|         +----------+            |
|         |          |            |
+---------------------------------+
|        Available letters        |
+---------------------------------+
|     A B C D E F G H I J K L M   |
|     N O P Q R S T U V W X Y Z   |
+---------------------------------+
|         Guess the word          |
+---------------------------------+
| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
+---------------------------------+
>
*/


class hangman
{
public:

void PrintMessage(string message, bool printTop = true, bool printBottom = true)//Function to print the lines and the message in a box
{
    if (printTop)
    {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else
    {
        cout << "|";
    }
    bool front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        if(front==true)
        {
            front=false;
        }
        else
        {
            front=true;
        }
    }
    cout << message.c_str();

    if (printBottom)
    {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else
    {
        cout << "|" << endl;
    }
}

  
  
void DrawHangman(int guessCount = 0)// Function to draw the hangman as the game proceeds
{
    if (guessCount >= 1)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 2)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 3)
        PrintMessage("O", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount == 4)
        PrintMessage("/  ", false, false);

    if (guessCount == 5)
        PrintMessage("/| ", false, false);

    if (guessCount >= 6)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 7)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount == 8)
        PrintMessage("/", false, false);

    if (guessCount >= 9)
        PrintMessage("/ \\", false, false);
    else
        PrintMessage("", false, false);
}

  
  
void PrintLetters(string input, char from, char to)//Function to print the available letters after guessing
{
    string s;
    for (char i = from; i <= to; i++)
    {
        if (input.find(i) == string::npos)
        {
            s += i;
            s += " ";
        }
        else
            s += "  ";
    }
    PrintMessage(s, false, false);
}

  
  
void PrintAvailableLetters(string taken)
{
    PrintMessage("Available letters");
    PrintLetters(taken, 'A', 'M');
    PrintLetters(taken, 'N', 'Z');
}

bool PrintWordAndCheckWin(string word, string guessed)//To print the updated word as it is being guessed
{
    bool won = true;
    string s;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    PrintMessage(s, false);
    return won;
}

  
  
string LoadRandomWord(string path)//to load a random word from the text file
{
    int lineCount = 0;
    string word;
    vector<string> v;
    ifstream reader(path);
    if (reader.is_open())
    {
        while (getline(reader, word))
            v.push_back(word);

        int randomLine = rand() % v.size();

        word = v.at(randomLine);
        reader.close();
    }
    return word;
}

  

bool has_only_alpha(string word) // To check if the word entered by the user is valid and only contain alphabets
{
    char c;
    for (int i = 0; i < word.length(); i++) {
        c = word.at(i);

        if (! ( ( c >= 'a' && c <= 'z' ) ||
                    ( c >= 'A' && c <= 'Z') ) ) {
            return false;
        }
    }
    return true;
}


  
int TriesLeft(string word, string guessed)//It returns the number of tries left
{
    int error = 0;
    for (int i = 0; i < guessed.length(); i++)
    {
        if (word.find(guessed[i]) == string::npos)
            error++;
    }
    return error;
}

  
  
void display()
{
    while(1)
    {

    int choice;
    system("cls");
    //MENU
    cout<<"=======WELCOME TO HANGMAN======="<<endl;
    cout<<"Ready to test your vocabulary!"<<endl<<endl;
    cout<<"Choose mode:-"<<endl;
    cout<<"(1)-1 player game"<<endl;
    cout<<"(2)-2 player game"<<endl;
    cout<<"(3)-Settings"<<endl;
    cout<<"(4)-Exit"<<endl<<endl;
    cout<<"Choice="<<endl;
    cin>>choice;
    //Class object
    //angman word_g;

    if(choice==2)
    {
        string guesses;
    string wordToGuess;
    int tries = 0;
    bool win = false;
    string n1;
    string n2;
    system("cls");
    cout<<"Player 1 will give the word while player 2 will guess it"<<endl;
    fflush(stdin);
    cout<<"Enter name of player 1:-";
    getline(cin,n1);
    cout<<"Enter name of player 2:-";
    getline(cin,n2);
    system("cls");
    cout<<"========="<<n1<<"'s turn========"<<endl;
    bool isValidWord = false;
    while (isValidWord == false) //Loop checking if the entered word is valid
    {

    cout << "Give me a word: ";
    cin >> wordToGuess;
    transform(wordToGuess.begin(), wordToGuess.end(), wordToGuess.begin(), ::toupper);
    isValidWord = has_only_alpha(wordToGuess);
    if (isValidWord)
    {
    for (int i = 0; i < 100; i++)
        { // clears the terminal
            cout << "\n" << endl;
         }
        break;
    }
    else
    {
    cout << "Only letters are allowed in words." << std::endl;
    }
    }

    cout<<"========="<<n2<<"'s turn"<<endl;
    do
    {
        system("cls"); //replace this line with system("clear"); if you run Linux or MacOS
        PrintMessage("HANGMAN");
        DrawHangman(tries);
        PrintAvailableLetters(guesses);
        PrintMessage("Guess the word");
        win = PrintWordAndCheckWin(wordToGuess, guesses);

        if (win)
            break;

        char x;
        cout << ">"; cin >> x;
        if(x>='a' && x<='z')
        {
            x=x-32;
        }

        if (guesses.find(x) == string::npos)
            guesses += x;

        tries = TriesLeft(wordToGuess, guesses);

    } while (tries < 10);

    if (win)
        cout<<"Congratulations "<<n2<<" won"<<endl;
    else
    {
        cout<<"The word was - "<<wordToGuess<<endl;
        cout<<"Sorry "<<n2<<" but "<<n1<<" won"<<endl;
    }
    system("pause");
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////
    else if(choice==1)
    {

    srand(time(0));
    string guesses;
    string wordToGuess;
    ifstream words_file;

    try {
        words_file.open("words.txt");
    }
    catch (...) {//words_file.fail()) {
        cout <<"Sorry some Error occured " << endl;
        cout<<"Please try again"<<endl;
        break;
    }
    words_file.close();
    wordToGuess = LoadRandomWord("words.txt");
    int tries = 0;
    bool win = false;
    do
    {
        system("cls"); //replace this line with system("clear"); if you run Linux or MacOS
        PrintMessage("HANGMAN");
        DrawHangman(tries);
        PrintAvailableLetters(guesses);
        PrintMessage("Guess the word");
        win =PrintWordAndCheckWin(wordToGuess, guesses);

        if (win)
            break;

        char x;
        cout << ">"; cin >> x;
        if(x>='a' && x<='z')
        {
            x=x-32;
        }

        if (guesses.find(x) == string::npos)
            guesses += x;

        tries = TriesLeft(wordToGuess, guesses);

    } while (tries < 10);

    if (win)
        PrintMessage("YOU WON!");
    else
        PrintMessage("GAME OVER");

    system("pause");
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    else if(choice==3)
    {
        cout<<"Enter words in the randomniser"<<endl;
        string s;
        char ch;
        ofstream file;
        file.open("words.txt",ios::app);
        while(1)
        {
            cout<<"Enter-";
            cin>>s;
            transform(s.begin(), s.end(), s.begin(), ::toupper);
            file<<s<<"\n";
            cout<<"Add new word Y or N"<<endl;
            cin>>ch;
            if(ch=='N'|| ch=='n')
            {
                break;
            }
            else if(ch=='Y'||ch=='y')
            {
                continue;
            }
            else
            {
                cout<<"Wrong choice"<<endl;
                break;
            }
        }
        file.close();
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////
    else if(choice==4)
    {
        break;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////
    else
    {
        cout<<"Wrong choice"<<endl;
    }
    }

}
};

int main()
{
    hangman obj;
    obj.display();
    return 0;
}
