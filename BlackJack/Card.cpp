#include "Card.h"

Card::Card(int value, int suit)
{
	this->value = value;
	this->suit = suit;
}

Card::Card() {}

Card::~Card() {}

int Card::getSuit() {
	return suit;
}

int Card::getValue() {
	return value;
}
