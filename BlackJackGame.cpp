#include "BlackJackGame.h"
#include "Player.h"

BlackJackGame::BlackJackGame(int numOfPlayer){
	bettingMoney = 0;
	this->deck = new Deck();
	this->numOfPlayer = numOfPlayer;
	for (int i = 0; i < numOfPlayer; i++)
		playerlist.push_back(new Player());
}

void BlackJackGame::gameplay() {
	
	char Continu = 'Y';
	Player* now_turn;
	char ch;

	while (Continu == 'Y') {
		if (betting()) {
			cout << "betting Money : " << bettingMoney << endl;
			distribute();
			while (!isAllStay()) {
				for (auto it = playerlist.begin(); it != playerlist.end(); it++) {
					now_turn = playerlist.at(it - playerlist.begin());
					if (now_turn->getIsStay() == false) {
						cout << "================================" << endl;
						cout << "==========< Player " << it - playerlist.begin() + 1 << " >==========" << endl;
						turn(now_turn);
					}
				}
			}

			dealerPlay();
			result();
			
			cout << "계속하시겠습니까??(Y/N)>>";
			cin >> Continu;			
		}
		else {
			cout << "베팅금액이 부족합니다." << endl;
			return;
		}

		initialize();
		system("cls");
	}
}

void BlackJackGame::distribute() {
	int index;

	if (deck->getSize() < (numOfPlayer + 1) * 4)
		deck->fill();

	cout << "==========< Dealer >===========" << endl;
	dealer.addCard(deck->draw());
	dealer.addCard(deck->draw());
	dealer.printDealer();
	
	for (auto it = playerlist.begin(); it != playerlist.end(); it++) {		
		index = it - playerlist.begin();
		(playerlist[index])->addCard(deck->draw());
		(playerlist[index])->addCard(deck->draw());
	}

}

void BlackJackGame::turn(Player* now) {

	now->printAll();
	now->calculateValue();
	now->printStatus();
	now->checkHand();

	while (now->getIsBust() == false & now->getIsBlackJack() == false) {

		char hitorstay;
		cout << "Hit or Stay?? (H/S) >> ";
		cin >> hitorstay;
		cout << endl;

		if (hitorstay == 'H') {
			now->addCard(deck->draw());
			now->printAll();
			now->calculateValue();
			now->checkHand();
			now->printStatus();
		}

		if (hitorstay == 'S')
			now->setIsStay(true);
			break;
	}
}

bool BlackJackGame::isAllStay() {
	int index;
	for (auto it = playerlist.begin(); it != playerlist.end(); it++) {
		index = it - playerlist.begin();
		if (playerlist[index]->getIsStay() == false)
			return false;
	}
	return true;
}

void BlackJackGame::initialize() {

	for (auto it = playerlist.begin(); it != playerlist.end(); it++)
		playerlist[it - playerlist.begin()]->initialize();

	dealer.initialize();
}

void BlackJackGame::dealerPlay() {
	dealer.calculateValue();

	if (dealer.getValue() < 17) {
		dealer.hit(deck->draw());
		dealer.calculateValue();
	}

	cout << "==========< Dealer >===========" << endl;
	dealer.checkHand();
	dealer.printAll();
	dealer.printStatus();
	
}

bool BlackJackGame::betting() {
	if (dealer.bet()) {
		bettingMoney += 1000;
	}
	for (auto it = playerlist.begin(); it != playerlist.end(); it++) {
		if (playerlist[it - playerlist.begin()]->bet())
			bettingMoney += 1000;
		else
			return false;
	}
	return true;
}

void BlackJackGame::result() {

	// 딜러 bust
	if (dealer.getIsBust() == true) {
		for (auto it = playerlist.begin(); it != playerlist.end(); it++) {
			if (playerlist[it - playerlist.begin()]->getIsBust() == false) {
				playerlist[it - playerlist.begin()]->addMoney(2000);
				dealer.subMoney(2000);
			}
			else {
				playerlist[it - playerlist.begin()]->addMoney(1000);
				dealer.subMoney(1000);
			}
		}
	}
	else {
		for (auto it = playerlist.begin(); it != playerlist.end(); it++) {
			if (playerlist[it - playerlist.begin()]->getIsBust() == false) {
				if (dealer.getValue() < playerlist[it - playerlist.begin()]->getValue()) {
					playerlist[it - playerlist.begin()]->addMoney(2000);
					dealer.subMoney(2000);
				}
				else if (dealer.getValue() == playerlist[it - playerlist.begin()]->getValue()) {
					playerlist[it - playerlist.begin()]->addMoney(1000);
					dealer.subMoney(1000);
				}		
			}
		}
	}

	dealer.addMoney(bettingMoney);
	bettingMoney = 0;

	cout << "===============================" << endl;
	cout << "============<Result>===========" << endl;
	
	cout << "Dealer Balance : ";
	dealer.printMoney();
	for (auto it = playerlist.begin(); it != playerlist.end(); it++) {
		cout << "Player " << it - playerlist.begin() + 1 << " : ";
		playerlist[it - playerlist.begin()]->printMoney();
	}
}
