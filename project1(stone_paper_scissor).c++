#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int RandomFunction(int from, int to) {
	int RandomNumber = rand() % (to - from + 1) + from;
	return RandomNumber;
}
int NumberOfRounnd() {
	int number;
	do {
		cout << "How Many Rounds 1 to 10 ?\n";
		cin >> number;
	} while (number <= 0 || number > 10);
	return number;
}
int NumberYouChoise() {
	int number;
	do {
		cout << "\nYour Choice: [1]:stone, [2]:paper, [3]:scissore ?";
		cin >> number;
	} while (number <= 0 || number > 3);
	return number;
}
enum enStoneOrPaperOrScissor { stone = 1, paper = 2, scissor = 3 };
string checkNumber(int number) {
	switch (number) {
	case enStoneOrPaperOrScissor::stone:
		return "stone";
	case enStoneOrPaperOrScissor::paper:
		return "paper";
	case enStoneOrPaperOrScissor::scissor:
		return "scissor";
	}
}
void checkWinner(int playerChoice, int computerChoice, int& counter1, int& counter2, int& draw) {
	if (playerChoice == computerChoice) {
		cout << "[No Winner]";
		system("color 6f");
		draw++;
	}
	else if (playerChoice == enStoneOrPaperOrScissor::paper && computerChoice == enStoneOrPaperOrScissor::stone) {
		cout << "[Plarer1]";
		system("color 2f");
		counter1++;
	}
	else if (playerChoice == enStoneOrPaperOrScissor::stone && computerChoice == enStoneOrPaperOrScissor::scissor) {
		cout << "[Plarer1]";
		system("color 2f");
		counter1++;
	}
	else if (playerChoice == enStoneOrPaperOrScissor::scissor && computerChoice == enStoneOrPaperOrScissor::paper) {
		cout << "[Plarer1]";
		system("color 2f");
		counter1++;
	}
	else if (playerChoice == enStoneOrPaperOrScissor::stone && computerChoice == enStoneOrPaperOrScissor::paper) {
		cout << "[Computer] \a";
		system("color 4f");
		counter2++;
	}
	else if (playerChoice == enStoneOrPaperOrScissor::scissor && computerChoice == enStoneOrPaperOrScissor::stone) {
		cout << "[Computer] \a";
		system("color 4f");
		counter2++;
	}
	else if (playerChoice == enStoneOrPaperOrScissor::paper && computerChoice == enStoneOrPaperOrScissor::scissor) {
		cout << "[Computer] \a";
		system("color 4f");
		counter2++;
	}
}
void RoundInformation(int playerChoice, int& counter1, int& counter2, int& draw) {
	int computerChoice = RandomFunction(1, 3);
	cout << "\nPlayer Choice  : " << checkNumber(playerChoice);
	cout << "\nComputer Choice: " << checkNumber(computerChoice);
	cout << "\nRound Winner     : ";
	checkWinner(playerChoice, computerChoice, counter1, counter2, draw);
}
void EndWinner(int counter1, int counter2, int draw) {
	if (counter1 > counter2 && counter1 >= draw) {
		cout << "[Player]";
	}
	else if (counter2 > counter1 && counter2 >= draw) {
		cout << "[Computer]";
	}
	else if (draw > counter1 && draw > counter2) {
		cout << "[No Winner]";
	}
}
void EndHeader() {
	cout << "\t\t---------------------------------\t\t\n";
	cout << "\t\t\t+++  G a m e  O v e r  ++\t\t\t\n";
	cout << "\t\t---------------------------------\t\t\n";
	cout << "\t\t-----------[Game Result]---------\t\t\n";
}
void EndResult(int numbrtOfRound, int counter1, int counter2, int draw) {
	cout << "\t\tGame Round         : " << numbrtOfRound << "\n";
	cout << "\t\tPlayer1 Won times  : " << counter1 << "\n";
	cout << "\t\tComputer won times : " << counter2 << "\n";
	cout << "\t\tDraw times         : " << draw << "\n";
	cout << "\t\tFinal winner      : ";
	EndWinner(counter1, counter2, draw);
}
void startGame(int numberOfRound, int playerChoice, int computerChoice, int& counter1, int& counter2, int& draw) {
	char choice;
	do {
		int counter1 = 0, counter2 = 0, draw = 0;
		system("cls");
		system("color 0f");
		numberOfRound = NumberOfRounnd();
		for (int i = 1; i <= numberOfRound; i++) {
			cout << "\nRound [" << i << "] begines:\n";
			int number = NumberYouChoise();
			cout << "\n----------Round[" << i << "]----------\n";
			RoundInformation(number, counter1, counter2, draw);
			cout << "\n--------------------------------------\n";
		}
		EndHeader();
		EndResult(numberOfRound, counter1, counter2, draw);
		cout << "\n\t\t---------------------------------\t\t\n";
		cout << "Do You want to play again ? Y/N ? ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}
int main()
{
	srand((unsigned)time(NULL));
	int numberOfRound = 0, playerChoice = 0, computerChoice = 0, counter1, counter2, draw;
	startGame(numberOfRound, playerChoice, computerChoice, counter1, counter2, draw);
	cout << "\n";
}