#pragma once
#include "Card.h"
#include <deque>

class Deck {
	deque <Card*> deck;		// Card Deck
public:
	Deck();				
	void shuffle();			// card deck shuffle function
	void fill();			// card deck�� �ٽ� ä��.
	void printAll();		// deck�� card�� ��� print
	int getSize();			// deck�� ���� ī�� �� �� �޾ƿ��� �Լ�
	Card* draw();			// Card Draw function
};
