#pragma once
#include "Player.h"

// Player class�� ��ӹ޴� Dealer class
class Dealer : public Player {
public:
	Dealer() : Player() {;}	// Dealer ������
	void printDealer();		// Dealer�� card info print(������ ó���� 1�常 open)
};
