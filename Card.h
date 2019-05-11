#pragma once
#include <string>
#include <iostream>
using namespace std;

// Shape : Hart(0) Diamond(1) Clover(2) Spade(3)
// num : ACE(1) 2 3 4 5 6 7 8 9 10 J(11) Q(12) K(13)
/* value
	Ace : 1 또는 11
	2 ~ 10 : 각 카드의 #number
	J Q K : 10
*/

class Card {
private:
	int shape;			// int type card shape
	string stringShape; // string type card shape
	int num;			// int type card num
	string stringNum;	// string type card num
public:
	Card(int shape, int num);											// Card 생성자
	string getShape() { return this->stringShape; }						// get string type card shape
	string getStringNum() { return this->stringNum; }					// get string type card number
	int getNum() { return this->num; }									// Get int type card number
	void print() { cout << stringNum << ' ' << stringShape << endl; }	// Print Card info
};
