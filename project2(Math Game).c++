#include <iostream>
#include <cstdlib>
using namespace std;
int RandomFunction(int from, int to) {
    int RandomNumber = rand() % (to - from + 1) + from;
    return RandomNumber;
}
int numberOfQuestions() {
    short number;
    do{
        cout << "How many questions do you want to answer ? ";
    cin >> number;
    } while (number < 1 || number>10);
    return number;
}
int QuestionLevel() {
    short number;
    do {
        cout << "Enter Question level [1]:Easy,[2]:Med,[3]:Hard,[4]:Mix ? ";
        cin >> number;
    } while (number < 1 || number>4);
    return number;
}
int OperationType() {
    short operation;
    do {
        cout << "Enter Operation type [1]:Add,[2]:Sub,[3]:Mul,[4]:Div,[5]:Mix ? ";
        cin >> operation;
    } while (operation < 1 || operation>5);
    return operation;
}
enum enQuestionLevels { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, mix = 5 };

int enQuestionLevels(short number) {
    switch (number) {
    case enQuestionLevels::Easy:
        return RandomFunction(1, 10);
    case enQuestionLevels::Med:
        return RandomFunction(10, 50);
    case enQuestionLevels::Hard:
        return RandomFunction(50, 100);
    case enQuestionLevels::Mix:
        short num = RandomFunction(1, 3);
        switch (num) {
        case enQuestionLevels::Easy:
            return RandomFunction(1, 10);
        case enQuestionLevels::Med:
            return RandomFunction(10, 50);
        case enQuestionLevels::Hard:
            return RandomFunction(50, 100);
        }
    }
}
string enquestionLevels(short number) {
    switch (number) {
    case enQuestionLevels::Easy:
        return "Easy";
    case enQuestionLevels::Med:
        return "Med";
    case enQuestionLevels::Hard:
        return "Hard";
    case enQuestionLevels::Mix:
        return "Mix";
    }
}
int  enOperationType(short numberOfLevel, short NumberOfOperation) {
    short result = 0;
    short number1 = enQuestionLevels(numberOfLevel);
    short number2 = enQuestionLevels(numberOfLevel);
    switch (NumberOfOperation) {
    case enOperationType::Add:
        cout << number1 << "\n" << number2 << " " << "+";
        cout << "\n\n--------------\n";
        return number1 + number2;
    case enOperationType::Sub:
        cout << number1 << "\n" << number2 << " " << "-";
        cout << "\n\n--------------\n";
        return number1 - number2;
    case enOperationType::Mul:
        cout << number1 << "\n" << number2 << " " << "*";
        cout << "\n\n--------------\n";
        return number1 * number2;
    case enOperationType::Div:
        cout << number1 << "\n" << number2 << " " << "/";
        cout << "\n\n--------------\n";
        return number1 / number2;
    case enOperationType::mix:
        short num = RandomFunction(1, 4);
        switch (num) {
        case enOperationType::Add:
            cout << number1 << "\n" << number2 << " " << "+";
            cout << "\n\n--------------\n";
            return number1 + number2;
        case enOperationType::Sub:
            cout << number1 << "\n" << number2 << " " << "-";
            cout << "\n\n--------------\n";
            return number1 - number2;
        case enOperationType::Mul:
            cout << number1 << "\n" << number2 << " " << "*";
            cout << "\n\n--------------\n";
            return number1 * number2;
        case enOperationType::Div:
            cout << number1 << "\n" << number2 << " " << "/";
            cout << "\n\n--------------\n";
            return number1 / number2;
        }
    }
}
string enoperationType(short number) {
    switch (number) {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mul:
        return "*";
    case enOperationType::Div:
        return "/";
    case enOperationType::mix:
        return "Mix";
    }
}
void CalculateResult(short numberOfLevel, short NumberOfOperation, short& RightCounter, short& WrongCounter) {
    short number = enOperationType(numberOfLevel, NumberOfOperation);
    short result = 0;
    cin >> result;
    if (result == number) {
        cout << "Right Answer :-)";
        RightCounter++;
        system("color 2f");
    }
    else {
        cout << "Wrong Answer \a:-(\n";
        system("color 4f");
        WrongCounter++;
        cout << "The right answer is : " << number << "\n";
    }
}
void PrintResultHeader(short RightCounter, short WrongCounter) {
    if (RightCounter >= WrongCounter) {
        cout << "------------------------------\n";
        cout << "Final Result is Pass :-)\n";
        cout << "------------------------------\n";
    }
    else {
        cout << "------------------------------\n";
        cout << "Final Result is Fail :-(\n";
        cout << "------------------------------\n";
    }
}
void FinalResult(short numberOfLevel, short numberOfquestion, short operationType, short RightCounter, short WrongCounter) {
    cout << "Number Of Questions     : " << numberOfquestion << "\n";
    cout << "Questions Level         :" << enquestionLevels(numberOfLevel) << "\n";
    cout << "Operation Type          :" << enoperationType(operationType) << "\n";
    cout << "Number Of Right Answers :" << RightCounter << "\n";
    cout << "Number Of Wrong Answers :" << WrongCounter << "\n";
    cout << "------------------------------\n";
}
void ResetScreen() {
    system("cls");
    system("color 0f");
}
void startGame(short NumberOfquestion, short numberOfOperation, short numberOfLevel, short RightCounter, short WrongCounter) {
    char playAgain = 'y';
    do {
        ResetScreen();
        NumberOfquestion = numberOfQuestions();
        numberOfLevel = QuestionLevel();
        numberOfOperation = OperationType();
        for (short i = 1; i <= NumberOfquestion; i++) {
            cout << "\nQuestion[" << i << "/" << NumberOfquestion << "]\n\n";
            CalculateResult(numberOfLevel, numberOfOperation, RightCounter, WrongCounter);
            cout << "\n\n";
        }
        PrintResultHeader(RightCounter, WrongCounter);
        FinalResult(numberOfLevel, NumberOfquestion, numberOfOperation, RightCounter, WrongCounter);
        cout << "\n";
        cout << "Do you want to play again ?  Y/N ?";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}
int main()
{
    srand((unsigned)time(NULL));
    short RightCounter = 0, WrongCounter = 0, NumberOfquestion = 0, numberOfOperation = 0, numberOfLevel = 0;
    startGame(NumberOfquestion, numberOfOperation, numberOfLevel, RightCounter, WrongCounter);
    cout << "\n";
}
