#pragma once
#include <deque>
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

class BlackJackGame {
private:
	int bettingMoney;			// 매 게임마다 베팅된 금액
	int numOfPlayer;			// 딜러를 제외한 플레이어의 수
	deque <Player*> playerlist;	// player를 담을 player list
	Dealer dealer;				// 딜러 객체 선언
public:
	BlackJackGame(int numOfPlayer);
	Deck* deck;					// 카드 덱 객체
	void gameplay();			// Game 시작함수
	void distribute();			// 딜러포함 모든 플레이어에게 2장씩 분배하는 함수
	void turn(Player* now);		// 각 플레이어의 턴을 진행하는 함수
	bool isAllStay();			// 모든 플레이어가 Stay 상태인지 확인
	void initialize();			// 매 게임마다 flag와 hand 초기화
	void dealerPlay();			// dealer play : dealer는 value 17이상 일 때 stay 17미만에서 hit
	bool betting();				// 베팅 함수
	void result();				// 베팅금액 분배 및 분배 후 결과 출력
};
