#pragma once
#include <vector>
#include "Card.h"

#define START_MONEY 10000

class Player{
protected:
	int money;				// 시작 머니
	vector <Card*> hand;	// 내 카드 저장을 위한 vector
	int value;				// Card Value
	bool isBlackJack;		// Blackjack 확인 flag
	bool isBust;			// Busted(22이상) 확인 flag
	bool isAce;				// Ace 유무 확인 flag
	bool isStay;			// Hit/Stay flag(True:Stay / False:Hit)
public:
	Player();
	void initialize();				// 드로우 전 내 카드vector와 flag 초기화
	void addCard(Card* newCard);	// 내 패에 카드 추가
	void hit(Card* newCard);		// hit : 한 장 더 드로우
	void stay();					// stay : 더 드로우 하지 않음

	void calculateValue();			// 내 카드 Value 계산
	int calculateAce();				// Ace 카드 Value 결정(1 or 11)
	void checkHand();				// 나의 패 확인

	void printAll();				// 내 모든 카드 Print
	void printStatus();				// value에 따른 상태 print

	int getValue();					// get value
	bool getIsBlackJack();			// get Blackjack flag
	bool getIsBust();				// get Bust flag
	bool getIsStay();				// get Stay flag
	void setIsStay(bool isStay);	// set Stay flag
	bool bet();						// 게임 시작시 마다 베팅할 수 있는 지 check & betting 하는 function
	void addMoney(int money);		// add money
	void subMoney(int money);		// subtract money
	void printMoney();				// print my money
	
};
