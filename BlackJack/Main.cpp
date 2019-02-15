#include <iostream>
#include <string>

#include "CardManager.h"
#include "Card.h"
#include "Delay.h"

using namespace std;

void clear();
int getValue(vector<Card>&);
void dealCards(vector<Card>&, vector<Card>&);
bool playRound(int);

const int SHUFFLE_AMT = 7;
const int DEALER_STY = 17;

CardManager* cardManager = nullptr;
bool quit = false;

int main() {
	cardManager = new CardManager();

	int decks;

	cout << "How many decks would you like to play with?" << endl;
	do {
		cin >> decks;
		if (decks > 20)
			cout << "Please enter a smaller number! (Under 20!)" << endl;
	} while (decks > 20);
	while (!quit) {
		playRound(decks);
	}
	return 0;
}


/* Returns true if the player wins.*/
bool playRound(int decks) {
	clear();
	cardManager->resetDeck(static_cast<unsigned int>(decks));
	cardManager->shuffle(SHUFFLE_AMT);

	vector<Card> dealer;
	vector<Card> player;

	bool playerBusted = false;
	bool dealerBusted = false;

	//Deal cards
	dealCards(dealer, player);

	clear();

	cout << "Dealer's cards are:" << endl;
	cout << "\t" << dealer.at(0).getTitle() << endl;
	cout << "\tUnknown" << endl;

	string input;

	while (input != "stay") {

		clear();

		cout << "Your cards are:" << endl;
		for (auto &card : player) {
			cout << "\t" << card.getTitle() << endl;
		}

		int score = getValue(player);

		if (score > 21) {
			playerBusted = true;
			cout << "You went over 21!" << endl;
			break;
		} else if (getValue(player) == 21) {
			cout << "BlackJack!!!" << endl;
			cout << "You won the round!";
			Delay::delay(7000L);
			return true;
		}

		clear();
		cout << R"(Would you like to "stay", "hit", or "quit"?)" << endl;
		cin >> input;

		if (input == "hit") {
			player.push_back(cardManager->getFromTop());
		} else if (input == "quit") {
			quit = true;
			return false;
		} else if (input != "stay") {
			cout << R"(Valid commands are "stay", "hit", and "quit")" << endl;
		}
	}

	Delay::delay(2500L);

	clear();

	cout << "Dealer's cards are:" << endl;
	for (auto& card : dealer) {
		cout << "\t" << card.getTitle() << endl;
	}

	while(getValue(dealer) < DEALER_STY) {
		clear();
		cout << "The dealer hit." << endl << endl;
		Delay::delay(2500L);
		dealer.push_back(cardManager->getFromTop());
		cout << "Dealer's cards are:" << endl;
		for (auto& card : dealer) {
			cout << "\t" << card.getTitle() << endl;
		}
	}

	if (getValue(dealer) == 21) {
		clear();
		cout << "The dealer hit a BlackJack!" << endl;
	} else if (getValue(dealer) > 21) {
		clear();
		cout << "The dealer busted!" << endl;
		dealerBusted = true;
	}

	if (dealerBusted && playerBusted) {
		clear();
		cout << "Nobody won the round!" << endl;
		Delay::delay(7000L);
		return false;
	} else if (dealerBusted) {
		clear();
		cout << "You won the round!" << endl;
		Delay::delay(7000L);
		return true;
	} else if (!playerBusted) {
		if (getValue(player) >= getValue(dealer)) {
			clear();
			cout << "You won the round!" << endl;
			Delay::delay(7000L);
			return true;
		}
	}


	clear();
	cout << "The dealer won the round!" << endl;
	Delay::delay(7000L);
	return false;
}

void dealCards(vector<Card>& dealer, vector<Card>& player) {
	for (int i = 0; i < 2; i++) {
		dealer.push_back(cardManager->getFromTop());
		player.push_back(cardManager->getFromTop());
	}
}

int getValue(vector<Card>& cards) {
	int total = 0;
	vector<Card> ace;
	for (Card& c : cards) {
		if (c.getValue() == 1) {
			ace.push_back(c);
		} else if (c.getValue() >= 10) {
			total += 10;
		} else {
			total += c.getValue();
		}
	}

	for (Card& c : ace) {
		total += total + 11 > 21 ? 1 : 11;
	}

	return total;
}

void clear() {
	cout << endl;
}