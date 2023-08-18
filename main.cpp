#include <iostream>
#include <cstdlib>
#include <ctime>
const int N = 15;

int main()
{
    srand ((unsigned) time(NULL));
    std::string wordList[10] = {"pilot", "hello", "balloon", "motorcycle", "letter", "driver", "word", "gino", "football", "engineer"};
    std::string word;
    std::string wordList_hatches[10] = {"_____", "_____", "_______", "__________", "______", "______", "____", "____", "________", "________"};
    std::string hidden;
    std::string hidden_Reset; //resetta tutti i tratteggi se l'utente fa troppi errori
    char letter;
    bool completed = false;
    bool letterFound = false;
    int random;
    int errors = 0;
    int totalErrors = 0;
    int inputCounter = 0;

    random = rand() % 10;
    word =  wordList[random]; 
    hidden = wordList_hatches[random]; 
    hidden_Reset = hidden; 

    std::cout<<"Guess the hidden word: "<<hidden<<'\n';

    do
    {
        std::cout<<std::endl<<"\nLetter: ";
        std::cin>>letter;

        for (int j = 0; j < word.length(); j++)
        {
            if(letter == word[j] )
            {
                letterFound = true;
            }
        }

        system("cls");

        //letteraTrovata ? std::cout<<"Lettera trovata!\n" : std::cout<<"Lettera non trovata!\n"; 
        if(letterFound)
        {
            std::cout<<"Letter found!\n";
        }
        else
        {
            std::cout<<"Letter not found!\n";
            errors++;
            totalErrors++;
        }

        if(letterFound)
        {
            for (int j = 0; j < word.length(); j++)
            {
                if(letter == word[j])
                {
                    hidden[j] = word[j];
                }
            }
        }

        if (errors == 4)
        {
            errors = 0;
            hidden = hidden_Reset;
        }
        

        std::cout<<std::endl<<hidden;
        letterFound = false;

        inputCounter++;

        if(hidden == word)
        {
            completed = true;
        }

    } while (!completed);

    std::cout<<"\nGG you won!\n";
    std::cout<<"You insert "<<inputCounter<<" characters!\n";
    std::cout<<"You made "<<totalErrors<<" errors!";

    return 0;
}