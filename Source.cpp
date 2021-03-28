/*This program is supposed to simulate a game of Blackjack 
* This a single player game
* The user is playing against the dealer to get to 21 or closest to 21
*/
#include<iostream>
#include<string>
#include<ctime>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//declarations
void setup();
void output();
void dealCard();
void checkSum();
void chooseForAce();
void afterFirstTurn();
int cardNum;
int playerSum = 0;
int blackJack = 21;
int bustNum = 22;
bool bust = true;
string name = "";
string playerChoice = "";

int main() {
	setup();
	while (cardNum <= bust) {
		dealCard();
		checkSum();
	}
}

//Simple introduction and takes the name the user inputs
void setup() {
	cout << "Welcome to the game of blackjack! :) " << endl;
	cout << "Please enter your name: ";
	cin >> name;
	cout << endl;
}

//This void function handles the first turn as well as set the random number generator
void dealCard() {
	srand(time(NULL));
	int cardNum = rand() % 13 + 1;
	cout << cardNum << endl;
	cout << name << " do you wish to stand (s) or hit (h)" << endl;
	cin >> playerChoice;
	afterFirstTurn();
}

//This void function checks the sum of all the cardNums up to each point its called
void checkSum() {
	if (cardNum > bustNum) {
		cout << "You lose" << endl;
	} else if (cardNum < bustNum) {
		cout << name << " do you wish to stand (s) or hit (h)" << endl;
		afterFirstTurn();
	}
	else if (cardNum = blackJack ) {
		cout << "Congrats " << name << " you got blackjack!";
	}
}

//This void functions checks to see if the player got the values 1 or 11 to let the player pick between the two numbers
void chooseForAce() {
	if (cardNum == 1 || 11) {
		cout << name << " do you wish to have 1 or 11?" << endl;
		cin >> cardNum; //change name
	}
}

void afterFirstTurn() {
	if (playerChoice == "h") {
		cout << "You chose to hit" << endl;
		cardNum = cardNum + cardNum;
	}
	else if (playerChoice == "s") {
		cout << "You chose to stand" << endl;
	}
}
