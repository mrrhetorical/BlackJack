#include "CardManager.h"
#include <algorithm>
#include <chrono>
#include <random>

CardManager::CardManager() {}


CardManager::~CardManager() {
	delete this;
}

Card CardManager::getFromTop() {
	const Card c = cards.at(0);
	cards.erase(cards.begin() + 0);
	return c;
}

void CardManager::shuffle(int times) {
	//More times means "more" randomness!
	for (int i = 0; i < times; i++) {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
	}
}

void CardManager::resetDeck(unsigned int decks) {
	cards.resize(0);
	for (unsigned int deck = 0; deck < decks; deck++) {
		for (int suit = 0; suit < 4; suit++) {
			for (int val = 1; val <= 13; val++) {
				Card card = (* new Card(val, suit));
				cards.push_back(card);
			}
		}
	}
}