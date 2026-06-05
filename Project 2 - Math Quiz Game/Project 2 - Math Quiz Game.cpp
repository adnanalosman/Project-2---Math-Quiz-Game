// Project 2 - Math Quiz Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

//Enum Groups

enum enLevel{Easy = 1, Mid, Hard, Mix};

enum enOperations{Add=1, Sub, Mul, Div, Mixture};


//Essential Functions

short ReadRange(short From, short To, string Message) {
    short Input;
    do {
        cout << Message;
        cin >> Input;
    } while (Input < From || Input > To);
    return Input;
}

float ReadMathInput(string Message) {
    float Input;
    cout << Message;
    cin >> Input;
    return Input;
}

short Random(short From, short To) {
    return rand() % (To - From + 1) + From;
}


//Math Functions

short Calculator(short Operation, short Num1, short Num2) {
    switch (Operation) {
    case enOperations::Add:
        return Num1 + Num2;
        break;
    case enOperations::Sub:
        return Num1 - Num2;
        break;
    case enOperations::Mul:
        return Num1 * Num2;
        break;
    case enOperations::Div:
        return Num1 / Num2;
        break;
    }
}

void MixOperation(short& Operation) {
    if (Operation == enOperations::Mixture)
    {
        Operation = Random(1, 4);
    }
}

//Rounds and Gameplay Functions

void GenNumRandomEasyToHard(short Level, short &Num1, short &Num2, short& Operation) {
    if (Level == enLevel::Easy)
    {
        Num1 = Random(1, 10);
        Num2 = Random(1, 10);
    }
    else if (Level == enLevel::Mid && Operation == enOperations::Sub)
    {
        Num1 = Random(10, 100);
        Num2 = Random(1, 10);
    }
    else if (Level == enLevel::Mid && Operation != enOperations::Sub)
    {
        Num1 = Random(1, 10);
        Num2 = Random(10, 100);
    }
    else if (Level == enLevel::Hard)
    {
        Num1 = Random(10, 100);
        Num2 = Random(10, 100);
    }
}


void RandomLevelBased(short Level, short &Num1, short &Num2, short& Operation) {
    if (Level==enLevel::Mix)
        GenNumRandomEasyToHard(Random(1, 3), Num1, Num2, Operation);
    else
        GenNumRandomEasyToHard(Level, Num1, Num2, Operation);
}

bool OperationResult(float Result,float UserResult) {
    if (Result == UserResult)
        return true;
    else
        return false;
}

void GamePlayResult(bool OperationResult, short &Win, short &Loose,float& Result) {
    if (OperationResult)
    {
        Win++;
        cout << "\nRight Answer :-)" << endl;
        system("color 2F");
    }
    else
    {
        Loose++;
        cout << "\nWrong Answer :-(" << endl;
        cout << "The Right Answer is: " << Result << endl;
        system("color 4F");
    }
}

string PrintOperation(short& Operation) {
    switch (Operation) {
    case enOperations::Add:
        return "+";
        break;
    case enOperations::Sub:
        return "-";
        break;
    case enOperations::Mul:
        return "x";
        break;
        case enOperations::Div:
        return "/";
        break;
    }
}

void Question(short &Round, short &Rounds, short &Level, short &Operation, short &Num1, short &Num2, float &UserResult) {
    cout << "\n\nQuestion [ " << Round << " / " << Rounds << " ]\n" << endl;
    cout << Num1 << endl << Num2 << "\t" << PrintOperation(Operation) << endl;
    cout << "___________" << endl;
    cin >> UserResult;
}

void RoundGamePlay(short Round, short &Rounds, short &Level, short &Operation, short& Win, short& Loose) {
    short Num1 = 0, Num2 = 0; float Result = 0, UserResult = 0;
    
    RandomLevelBased(Level, Num1, Num2, Operation); //to generate random Numbers
    Question(Round, Rounds, Level, Operation, Num1, Num2, UserResult); //Ask user the question and update the user result
    Result = Calculator(Operation, Num1, Num2);

    GamePlayResult(OperationResult(Result, UserResult), Win, Loose, Result);
}

string GameResult(short& Win, short& Loose) {
    if (Win > Loose)
    {
        system("color 2F");
        return "Winner :-)";
    }
    else {
        system("color 4F");
        return "Looser, Game Over! :-(";
    }
}

void GetGamePlayReport(short& Rounds, short& Win, short& Loose) {
    cout << "\t\t\t\t__________________________________________\n\n\t\t\t\t+ + +  G A M E  R E P O R T   + + +\n\t\t\t\t__________________________________________\n" << endl;
    cout << "\t\t\t\tGame Rounds       : " << Rounds << endl;
    cout << "\t\t\t\tPlayer Win Times  : " << Win << endl;
    cout << "\t\t\t\tPlayer Loose Times: " << Loose << endl;
    cout << "\t\t\t\tGameplay Result   : " << GameResult(Win,Loose) << endl;
}

void GamePlay() {
    short Win = 0, Loose = 0;
    short Rounds = ReadRange(1, 10, "Please Select Rounds of Game? (1 ~ 10): ");
    short Level = ReadRange(1, 4, "\nSelect Questions Level: [1] Easy, [2] Mid, [3] Hard, [4] Mix? ");
    short Operation = ReadRange(1, 5, "\nSelect Operation Type: [1] Add(+), [2] Subtraction(-), [3] Multiplication(x), [4] Division (/) [5] Mix? ");
    MixOperation(Operation);

    for (int i = 0; i < Rounds; i++) {
        RoundGamePlay(i+1, Rounds, Level, Operation, Win, Loose);
    }
    
    GetGamePlayReport(Rounds, Win, Loose);
}

void NewGame() {
    char NewRound = 'Y';
    do
    {
        system("color 07");
        system("cls");
        GamePlay();
        cout << endl << "\n\t\t\t\t__________________________________________\n\n\t\t\t\t\tW A N T   P L A Y   M O R E ?\n\t\t\t\t__________________________________________" << endl;
        cout << "\n\n\t\t\t\t\t[ N ] N O \t[ Y ] Y E S\n\n\t\t\t\t\t\t     ";
        cin >> NewRound;

    } while (NewRound == 'Y' || NewRound == 'y');
}




//Report Group Functions







int main()
{
    srand((unsigned)time(NULL));

    NewGame();


    return 0;
}
