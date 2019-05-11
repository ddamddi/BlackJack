#include <random>
#include <chrono>
#include "Deck.h"

Deck::Deck() {
	// cout << "Deck Class 생성자 실행" << endl;
	fill();
	shuffle();
}
void Deck::shuffle() {
	srand(unsigned(time(NULL)));
	random_shuffle(deck.begin(), deck.end());
}
void Deck::fill() {
	deck.clear();
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++){
			deck.push_back(new Card(i,j));
		}
	}
	cout << "refill deck..." << endl;
}
void Deck::printAll() {
	for (auto it = deck.begin(); it != deck.end(); it++)
		deck[it - deck.begin()]->print();
}
int Deck::getSize() {
	return deck.size();
}
Card* Deck::draw() {
	Card* tmp = deck[0];
	deck.pop_front();
	return tmp;
}
