#pragma once
#include <vector>
#include "Card.h"

#define START_MONEY 10000

class Player{
protected:
	int money;				// ���� �Ӵ�
	vector <Card*> hand;	// �� ī�� ������ ���� vector
	int value;				// Card Value
	bool isBlackJack;		// Blackjack Ȯ�� flag
	bool isBust;			// Busted(22�̻�) Ȯ�� flag
	bool isAce;				// Ace ���� Ȯ�� flag
	bool isStay;			// Hit/Stay flag(True:Stay / False:Hit)
public:
	Player();
	void initialize();				// ��ο� �� �� ī��vector�� flag �ʱ�ȭ
	void addCard(Card* newCard);	// �� �п� ī�� �߰�
	void hit(Card* newCard);		// hit : �� �� �� ��ο�
	void stay();					// stay : �� ��ο� ���� ����

	void calculateValue();			// �� ī�� Value ���
	int calculateAce();				// Ace ī�� Value ����(1 or 11)
	void checkHand();				// ���� �� Ȯ��

	void printAll();				// �� ��� ī�� Print
	void printStatus();				// value�� ���� ���� print

	int getValue();					// get value
	bool getIsBlackJack();			// get Blackjack flag
	bool getIsBust();				// get Bust flag
	bool getIsStay();				// get Stay flag
	void setIsStay(bool isStay);	// set Stay flag
	bool bet();						// ���� ���۽� ���� ������ �� �ִ� �� check & betting �ϴ� function
	void addMoney(int money);		// add money
	void subMoney(int money);		// subtract money
	void printMoney();				// print my money
	
};
