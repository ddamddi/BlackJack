#pragma once
#include "Player.h"

// Player class를 상속받는 Dealer class
class Dealer : public Player {
public:
	Dealer() : Player() {;}	// Dealer 생성자
	void printDealer();		// Dealer의 card info print(딜러는 처음에 1장만 open)
};
