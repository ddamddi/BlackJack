#include <iostream>
#include "BlackJackGame.h"
#include "Player.h"
using namespace std;

int main() {
	
	int numOfPlayer;
	cout << "���� ������ �����մϴ�" << endl;
	cout << "������ �÷��̾� ��(��������)�� �Է��ϼ��� >> ";
	cin >> numOfPlayer;
	
	BlackJackGame game(numOfPlayer);
	game.gameplay();
	cout << "������ �����մϴ�" << endl;
	
}

