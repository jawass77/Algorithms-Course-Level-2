#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

enum enOperationType
{
    Add = 1,
    sub = 2,
    mul = 3,
    Div = 4,
    Max = 5
};

enum enQuestionsLevel
{
    easy = 1,
    med = 2,
    hard = 3,
    max = 4
};

struct stQuestionInfo
{
    int FirstNumber;
    int SecondNumber;
    int result;
    int playerResult;
    enQuestionsLevel QuestionsLevel;
    enOperationType OperationType;
    bool TrueResult = true;
};

struct stGameInfo
{
    stQuestionInfo QuestionInfo[100];
    int NumberOfQuestions = 0;
    int NumberRound = 0;
    enQuestionsLevel QuestionsLevel;
    enOperationType OperationType;
    int RightAnswers = 0;
    int wrongAnswers = 0;
};

int ReadPostiveNumber(string text)
{

    int num;
    do
    {
        cout << text;
        cin >> num;
    } while (num < 0||num>100);

    return num;
}

int ReadQuestionAnswer()
{

    int num;
    do
    {
        cout << "How many questions do you want to answer ? ";
        cin >> num;
    } while (num < 0||num>100);

    return num;
}


int randomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enQuestionsLevel readQuestionsLevel()
{
    int QuestionLevel;
    do
    {
        QuestionLevel = ReadPostiveNumber("Enter question level [1]easy, [2]med, [3]hard, [4]max ?");
    } while (QuestionLevel < 1 && QuestionLevel > 4);

    return (enQuestionsLevel)QuestionLevel;
}

enOperationType readOperationType()
{
    int OperationType;
    do
    {
        OperationType = ReadPostiveNumber("Enter operation type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix ?");
    } while (OperationType < 1 && OperationType > 5);

    return (enOperationType)OperationType;
}

int GetNumberToAsk(enQuestionsLevel QuestionLevel)
{
    switch (QuestionLevel)
    {
    case enQuestionsLevel::easy:
        return randomNumber(1, 9);
        break;
    case enQuestionsLevel::med:
        return randomNumber(10, 49);
        break;
    case enQuestionsLevel::hard:
        return randomNumber(50, 99);
        break;
    }
}

int GetResult(int FirstNumber, int SecondNumber, enOperationType &OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Add:
        return FirstNumber + SecondNumber;
        break;
    case enOperationType::sub:
        return FirstNumber - SecondNumber;
        break;
    case enOperationType::mul:
        return FirstNumber * SecondNumber;
        break;
    case enOperationType::Div:
        return FirstNumber / SecondNumber;
        break;
    }
}

stQuestionInfo GetQuestionWithResult(enOperationType OperationType, enQuestionsLevel QuestionLevel)
{
    stQuestionInfo QuestionInfo;

    if (QuestionLevel == enQuestionsLevel::max)
        QuestionLevel = (enQuestionsLevel)randomNumber(1, 3);
    
    QuestionInfo.QuestionsLevel = QuestionLevel;

    if (OperationType == enOperationType::Max)
        OperationType = (enOperationType)randomNumber(1, 4);

    QuestionInfo.OperationType = OperationType;

    QuestionInfo.FirstNumber = GetNumberToAsk(QuestionInfo.QuestionsLevel);
    QuestionInfo.SecondNumber = GetNumberToAsk(QuestionInfo.QuestionsLevel);
    QuestionInfo.result = GetResult(QuestionInfo.FirstNumber, QuestionInfo.SecondNumber, QuestionInfo.OperationType);

    return QuestionInfo;
}

char PrintOperationType(enOperationType OprerationType)
{
    switch (OprerationType)
    {
    case enOperationType::Add:
        return '+';
        break;
    case enOperationType::sub:
        return '-';
        break;
    case enOperationType::mul:
        return '*';
        break;
    case enOperationType::Div:
        return '/';
        break;
    default:
        return '?';
        break;
    }
}

bool checkPlayerResult(int PlayerResult, int result)
{
    if (PlayerResult == result)
        return true;
    else
        return false;
}

void PrintTheQuestion(stGameInfo GameInfo)
{
    char OperationType = PrintOperationType(GameInfo.QuestionInfo[GameInfo.NumberRound].OperationType);

        cout << "Question [" << GameInfo.NumberRound + 1 << "/" << GameInfo.NumberOfQuestions << "]\n\n";
        cout << GameInfo.QuestionInfo[GameInfo.NumberRound].FirstNumber << endl;
        cout << GameInfo.QuestionInfo[GameInfo.NumberRound].SecondNumber << " " << OperationType << endl
             << endl;
        cout << "_________\n";

}

void QuestionBegin(stGameInfo &GameInfo)
{
    for (int i = 0; i < GameInfo.NumberOfQuestions; i++)
    {
        GameInfo.QuestionInfo[i] = GetQuestionWithResult(GameInfo.OperationType, GameInfo.QuestionsLevel);

        PrintTheQuestion(GameInfo);

        cin >> GameInfo.QuestionInfo[i].playerResult;

        GameInfo.QuestionInfo[i].TrueResult = checkPlayerResult(GameInfo.QuestionInfo[i].playerResult, GameInfo.QuestionInfo[i].result);

        if (GameInfo.QuestionInfo[i].TrueResult)
        {
            cout << "Right answer :)\n";
            GameInfo.RightAnswers++;
            system("color 2F");
        }
        else
        {
            cout << "wrong answer :(\n";
            cout << "The right answer is " << GameInfo.QuestionInfo[i].result << endl;
            GameInfo.wrongAnswers++;
            system("color 4F");
        }
        GameInfo.NumberRound++;
    }
}

bool checkPass(stGameInfo GameInfo)
{
    return (GameInfo.RightAnswers >= GameInfo.wrongAnswers);
}

string GetNameFinalResult(bool name)
{
    switch (name)
    {
    case true:
        return "Pass";
        break;

    default:
        return "Fail";
        break;
    }
}

string GetNameOperationType(enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Add:
        return "Add";
        break;
    case enOperationType::sub:
        return "Sub";
        break;
    case enOperationType::mul:
        return "Mul";
        break;
    case enOperationType::Div:
        return "Div";
        break;
    case enOperationType::Max:
        return "Mex";
        break;
    }
}

string GetNameQuestionLevel(enQuestionsLevel QuestionLevel)
{
    switch (QuestionLevel)
    {
    case enQuestionsLevel::easy:
        return "Easy";
        break;
    case enQuestionsLevel::med:
        return "Med";
        break;
    case enQuestionsLevel::hard:
        return "Hard";
        break;
    case enQuestionsLevel::max:
        return "Mex";
        break;
    }
}

void FinalResult(stGameInfo GameInfo)
{
    cout << "__________________________________\n\n";
    cout << "   final result is " << GetNameFinalResult(checkPass(GameInfo)) << endl;
    cout << "__________________________________\n\n";
    cout << "Number of questions   : " << GameInfo.NumberOfQuestions << endl;
    cout << "Questions level       : " << GetNameQuestionLevel(GameInfo.QuestionsLevel) << endl;
    cout << "Operation type        : " << GetNameOperationType(GameInfo.OperationType) << endl;
    cout << "Number of right answer: " << GameInfo.RightAnswers << endl;
    cout << "Number of wrong answer: " << GameInfo.wrongAnswers << endl;
    cout << "_________________________\n";
    if (checkPass(GameInfo))
        system("color 2F");
    else
        system("color 4F");
}

void resetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char agein = 'y';
    do
    {
        resetScreen();

        stGameInfo gameInfo;
        gameInfo.NumberOfQuestions = ReadQuestionAnswer();
        gameInfo.QuestionsLevel = readQuestionsLevel();
        gameInfo.OperationType = readOperationType();

        QuestionBegin(gameInfo);

        FinalResult(gameInfo);

        cout << "Do you want to play again ? y/n ?";
        cin >> agein;

    } while (agein == 'Y' || agein == 'y');
}

int main()
{
    srand(time(NULL));

    StartGame();
}