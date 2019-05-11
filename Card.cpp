#include "Card.h"

// Shape : Hart(0) Diamond(1) Clover(2) Spade(3)
// num : ACE(1) 2 3 4 5 6 7 8 9 10 J(11) Q(12) K(13)
/* value
	Ace : 1 또는 11
	2 ~ 10 : 각 카드의 #number
	J Q K : 10
*/

Card::Card(int shape, int num) {
	// cout << "Card Class 생성자 실행" ;
	this->shape = shape;
	this->num = num;
	// cout << '\t' << num << " " << shape << endl;
	switch (shape) {
	case 0: this->stringShape = "Hart"; break;
	case 1: this->stringShape = "Diamond"; break;
	case 2: this->stringShape = "Clover"; break;
	case 3: this->stringShape = "Spade"; break;
	}

	switch (num) {
	case 1: this->stringNum = "Ace"; break;
	case 2: this->stringNum = "Two"; break;
	case 3: this->stringNum = "Three"; break;
	case 4: this->stringNum = "Four"; break;
	case 5: this->stringNum = "Five"; break;
	case 6: this->stringNum = "Six"; break;
	case 7: this->stringNum = "Seven"; break;
	case 8: this->stringNum = "Eight"; break;
	case 9: this->stringNum = "Nine"; break;
	case 10: this->stringNum = "Ten"; break;
	case 11: this->stringNum = "Jack"; break;
	case 12: this->stringNum = "Queen"; break;
	case 13: this->stringNum = "King"; break;
	}

}
