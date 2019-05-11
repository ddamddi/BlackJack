#pragma once
#include <deque>
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

class BlackJackGame {
private:
	int bettingMoney;			// �� ���Ӹ��� ���õ� �ݾ�
	int numOfPlayer;			// ������ ������ �÷��̾��� ��
	deque <Player*> playerlist;	// player�� ���� player list
	Dealer dealer;				// ���� ��ü ����
public:
	BlackJackGame(int numOfPlayer);
	Deck* deck;					// ī�� �� ��ü
	void gameplay();			// Game �����Լ�
	void distribute();			// �������� ��� �÷��̾�� 2�徿 �й��ϴ� �Լ�
	void turn(Player* now);		// �� �÷��̾��� ���� �����ϴ� �Լ�
	bool isAllStay();			// ��� �÷��̾ Stay �������� Ȯ��
	void initialize();			// �� ���Ӹ��� flag�� hand �ʱ�ȭ
	void dealerPlay();			// dealer play : dealer�� value 17�̻� �� �� stay 17�̸����� hit
	bool betting();				// ���� �Լ�
	void result();				// ���ñݾ� �й� �� �й� �� ��� ���
};
