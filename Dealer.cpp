#include "Dealer.h"

void Dealer::printDealer() {
	hand.at(0)->print();					// Card 한 장만 open
	cout << "#############" << endl;		// 뒤집힌 카드를 표현
	cout << "--------------------------------" << endl;
	
	// Open한 카드 한 장의 value 계산
	int tmp = hand[0]->getNum();
	if (tmp >= 10)	
		tmp = 10;
	else if (tmp == 1)				
		tmp = 11;
	cout << "value : " << tmp << endl;
}
