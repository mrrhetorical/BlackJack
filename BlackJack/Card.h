#pragma once

#include <string>

using std::string;

class Card
{
private:
	int suit;
	int value;
public:
	Card();
	Card(int, int);
	~Card();
	int getSuit();
	int getValue();
	string getTitle() {
		string value;
		if (getValue() <= 10 && getValue() > 1) {
			 value = std::to_string(getValue());
		} else if (getValue() == 1) {
			value = "Ace";
		} else if (getValue() == 11) {
			value = "Jack";
		} else if (getValue() == 12) {
			value = "Queen";
		} else if (getValue() == 13) {
			value = "King";
		}

		string suit;

		switch(getSuit()) {
			case 0:
				suit = "Spades";
				break;
			case 1:
				suit = "Diamonds";
				break;
			case 2:
				suit = "Clubs";
				break;
			case 3:
				suit = "Hearts";
				break;
			default:
				break;
		}

		return value + " of " + suit;
	}
};

