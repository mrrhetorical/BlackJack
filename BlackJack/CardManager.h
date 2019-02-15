#pragma once
#include "Card.h"

#include <vector>

using namespace std;

class CardManager
{
private:
	vector<Card> cards;
public:
	CardManager();
	~CardManager();
	void shuffle(int);
	Card getFromTop();
	void resetDeck(unsigned int);
};

