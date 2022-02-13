//this gives us cces to  libry of code needed to mek triple x functionl
#include <iostream>
#include <ctime>

void PrintIntroduction(int level)
{
    //This prt shows the plyer  introduction in the form of text
    std::cout << "\n\nYou're  secret agent breaking into a level " << level;
    //std::cout << std::endl;  <--- this or ---> "\n" is both correct to end  line
    std::cout << " secure server room \nYou need to enter the correct code to continue... \n\n";
}

bool PlayGame(int level)
{
    srand(time(NULL)); // creates a new random seed based on time
    PrintIntroduction(level);

    // there re some vribles here tht re mde nd hve  vlue given out, the "const" prt
    // mkes sure tht the vlue will not be chnged!
    const int CodeA = rand() % level + level;
    const int CodeB = rand() % level + level;
    const int CodeC = rand() % level + level;

    //over here vribles re mde nd declred s well
    //however the vribles here re declred by mking use of
    //erlier declred vribles nd then dded up to echother or multiply by
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    int GuessA, GuessB, GuessC;
    int GuessSum;
    int GuessProduct;

    std::cout << "There are 3 numbers in the code" << std::endl;
    std::cout << "The code add up to: " << CodeSum << std::endl;

    //std::cout << "The code dd up to " + CodeSum << std::endl;

    std::cout << "The code multiply to give: " << CodeProduct << std::endl;
    std::cin >> GuessA >> GuessB >> GuessC;
    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    //this works as well
    /*
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    */

    std::cout << "\nYou filled in: " << GuessA << GuessB << GuessC << std::endl;
    std::cout << "with your guess it will add up to " << GuessSum << std::endl;
    std::cout << "With your guess it will multiply up to: " << GuessProduct << std::endl;

    //if the player got ir
    if (GuessProduct == CodeProduct && GuessSum == CodeSum)
    {
        std::cout << "\n*** You got it right, good job agent, now keep going. ***";
        return true;
    }
    else // if first condition isn't met (player is right) then the player could only be wrong
    {
        std::cout << "\n*** Be carefull, you got it wrong. The alarm may be raised next time, try again! ***";
        return false;
    }
}

//int min mkes sure tht the code will be running and executed
int main()
{
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;


    while(LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n*** Well done agent, you hacked through everything, now return to base ***";

    //this part is the end of the "min" function
    return 0;
}