// the progect is game stone paper scissors.
#include <iostream>
#include <time.h>

using namespace std;

enum enChoose
{
    stone = 1,
    Paper = 2,
    Scissors = 3
};

enum enPlayer
{
    computer = 1,
    player1 = 2,
    draw = 3
};

struct stRoundInfo
{
    int NumberRound = 0;
    enChoose Player1Choice;
    enChoose ComputerChoice;
    enPlayer winner;
    string nameWinner;
};

struct strDataGame
{
    int playerWin = 0;
    int computerWin = 0;
    int drawWin = 0;
};

int ReadPostiveNumber(string text)
{

    int num;
    do
    {
        cout << text << endl;
        cin >> num;
    } while (num < 0);

    return num;
}

int randomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enPlayer CheckWinner(stRoundInfo roundInfo, strDataGame &GameData)
{
    if (roundInfo.Player1Choice == roundInfo.ComputerChoice)
    {
        GameData.drawWin++;
        system("color 6F");//screen yellow.
        return enPlayer::draw;
    }
    else if (roundInfo.Player1Choice == enChoose::stone && roundInfo.ComputerChoice == enChoose::Scissors)
    {
        GameData.playerWin++;
        system("color 2F");//screen Green.
        return enPlayer::player1;
    }
    else if (roundInfo.Player1Choice == enChoose::Scissors && roundInfo.ComputerChoice == enChoose::Paper)
    {
        GameData.playerWin++;
        system("color 2F");//screen Green.
        return enPlayer::player1;
    }
    else if (roundInfo.Player1Choice == enChoose::Paper && roundInfo.ComputerChoice == enChoose::stone)
    {
        GameData.playerWin++;
        system("color 2F");//screen Green.
        return enPlayer::player1;
    }
    else
    {
        GameData.computerWin++;
        system("color 4F");//screen red.
        cout<<"\a";
        return enPlayer::computer;
    }
}

string nameChoice(enChoose Choose)
{
    if (Choose == Paper)
        return "Paper";
    else if (Choose == stone)
        return "Stone";
    else if (Choose == Scissors)
        return "Scissors";
}

string nameWinner(enPlayer name)
{
    string NameWin[3] = {"computer", "player1", "draw"};

    return NameWin[name - 1];
}

void PrintRound(stRoundInfo roundInfo)
{
    cout << "____________Round [" << roundInfo.NumberRound << "] ______________\n\n";
    cout << "Player1 Choice  : " << nameChoice(roundInfo.Player1Choice) << endl;
    cout << "Computer choice : " << nameChoice(roundInfo.ComputerChoice) << endl;
    cout << "Round winner    : " << roundInfo.nameWinner << endl
         << endl;
    cout << "___________________________________________\n\n\n";
}

enChoose ReadPlayerChoice()
{
    int PlayerChoice;
    do
    {
        PlayerChoice = ReadPostiveNumber("your choice: [1]stone, [2]paper, [3]scissors ?");

    } while (PlayerChoice < 1 || PlayerChoice > 3);

    return (enChoose)PlayerChoice;
}

enChoose GetComputerChoice()
{
    return (enChoose)randomNumber(1, 3);
}

void resultsRound(int NumberRound, strDataGame &GameData)
{
    stRoundInfo roundInfo;
    roundInfo.NumberRound=NumberRound;
    cout << "Round [" << roundInfo.NumberRound << "] begins:\n\n";
    roundInfo.Player1Choice = ReadPlayerChoice();
    roundInfo.ComputerChoice = GetComputerChoice();
    roundInfo.winner = CheckWinner(roundInfo, GameData);
    roundInfo.nameWinner = nameWinner(roundInfo.winner);

    PrintRound(roundInfo);
}

void AllRounds(int NumberRound, strDataGame &GameData)
{
    for (int i = 1; i <= NumberRound; i++)
    {
        resultsRound(i, GameData);
    }
}

string NameFinalWinnar(strDataGame GameData)
{
    if (GameData.playerWin > GameData.computerWin)
        return "player winner";
    else if (GameData.playerWin < GameData.computerWin)
        return "computer winner";
    else if (GameData.playerWin == GameData.computerWin)
        return "draw winner";
}

void GameOverScreen()
{
    cout << "________________________________________________\n\n";
    cout << "___________+++ G a m e  O v e r +++_____________\n\n";
    cout << "________________________________________________\n\n";
}

void resultGame(int NumberRound, strDataGame GameData)
{
    cout << "_______________[ Game result ]__________________\n\n";
    cout << "Game Round         : " << NumberRound << endl;
    cout << "Player1 won times  : " << GameData.playerWin << endl;
    cout << "computer won times : " << GameData.computerWin << endl;
    cout << "Draw times         : " << GameData.drawWin << endl;
    cout << "Final winner       : " << NameFinalWinnar(GameData) << endl
         << endl;
    cout << "________________________________________________\n\n";
}

void resetScreen()
{
    system("cls");
    system("color 0F");
}
void startGame()
{
    char PlayAgain='y';
    do
    {
        resetScreen();
        strDataGame GameData;

    int numberRound = ReadPostiveNumber("How many rounds 1 to 10 ?");

    AllRounds(numberRound, GameData);

    GameOverScreen();
    resultGame(numberRound, GameData);

    cout<<endl<<"Do you want play again? Y/N? ";
    cin>>PlayAgain;

    } while (PlayAgain=='y'||PlayAgain=='Y');
    
}

int main()
{
    srand(time(0));

    startGame();
}