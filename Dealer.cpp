#include "Dealer.h"

void Dealer::printDealer() {
	hand.at(0)->print();					// Card �� �常 open
	cout << "#############" << endl;		// ������ ī�带 ǥ��
	cout << "--------------------------------" << endl;
	
	// Open�� ī�� �� ���� value ���
	int tmp = hand[0]->getNum();
	if (tmp >= 10)	
		tmp = 10;
	else if (tmp == 1)				
		tmp = 11;
	cout << "value : " << tmp << endl;
}
