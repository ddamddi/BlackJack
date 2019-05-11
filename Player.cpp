#include "Player.h"

Player::Player() {
	this->value = 0;
	this->money = START_MONEY;
	initialize();
}
void Player::initialize() {
	this->hand.clear();
	isBlackJack = false;
	isBust = false;
	isAce = NULL;
	isStay = false;
}

void Player::addCard(Card* newCard) {
	this->hand.push_back(newCard);
}

void Player::hit(Card* newCard) {
	addCard(newCard);
}

void Player::stay() {
	/* Nothing happen */
}

void Player::calculateValue() {
	value = 0;

	for (auto it = hand.begin(); it != hand.end(); it++) {
		int tmp = hand[it - hand.begin()]->getNum();

		if (tmp >= 10)					// 10 J Q K --> 10
			value += 10;	

		else if (tmp > 1)				// 2 ~ 9 --> 2 ~ 9 
			value += tmp;

		else if (tmp == 1)				// Ace --> 1 or 11
			value += calculateAce();	
	}
}

int Player::calculateAce() {
	int tempValue;
	if (isAce == NULL) {
		tempValue = 11 + value;
		if (tempValue <= 21) {
			isAce = true;
			return 11;
		}
		else {
			isAce = false;
			return 1;
		}
	}
	else if (isAce) {
		tempValue = 11 + value;
		if (tempValue <= 21) {
			isAce = true;
			return 11;
		}
		else {
			isAce = false;
			return 1;
		}
	}
	else {
		isAce = false;
		return 1;
	}
}

void Player::checkHand() {
	if (value < 21) {
		isBlackJack = false;
		isBust = false;
	}
	else if (value == 21) {
		isBlackJack = true;
		isBust = false;
		isStay = true;
	}
	else {
		isBust = true;
		isStay = true;
	}
}

void Player::printAll() {
	for (auto it = hand.begin(); it != hand.end(); it++)
		hand[it - hand.begin()]->print();
}

void Player::printStatus() {
	cout << "--------------------------------" << endl;
	cout << "value : " << value << endl;
	if (value == 21)
		cout << "BlackJack" << endl;
	else if (value > 21)
		cout << "Busted!" << endl;
	else
		cout << "Good!" << endl;
}
int Player::getValue() {
	return value;
}
bool Player::getIsBlackJack() {
	return isBlackJack;
}
bool Player::getIsBust() {
	return isBust;
}
bool Player::getIsStay() {
	return isStay;
}
void Player::setIsStay(bool isStay) {
	this->isStay = isStay;
}
bool Player:: bet() {
	if (money < 1000)
		return false;
	else {
		money -= 1000;
		return true;
	}
}
void Player::addMoney(int money) {
	this->money += money;
}
void Player::subMoney(int money) {
	this->money -= money;
}
void Player::printMoney() {
	cout << money << endl;
}
