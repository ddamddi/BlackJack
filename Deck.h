#pragma once
#include "Card.h"
#include <deque>

class Deck {
	deque <Card*> deck;		// Card Deck
public:
	Deck();				
	void shuffle();			// card deck shuffle function
	void fill();			// card deck을 다시 채움.
	void printAll();		// deck의 card를 모두 print
	int getSize();			// deck의 남은 카드 장 수 받아오는 함수
	Card* draw();			// Card Draw function
};
