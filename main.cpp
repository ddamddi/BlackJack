#include <iostream>
#include "BlackJackGame.h"
#include "Player.h"
using namespace std;

int main() {
	
	int numOfPlayer;
	cout << "블랙잭 게임을 시작합니다" << endl;
	cout << "참여할 플레이어 수(딜러제외)를 입력하세요 >> ";
	cin >> numOfPlayer;
	
	BlackJackGame game(numOfPlayer);
	game.gameplay();
	cout << "게임을 종료합니다" << endl;
	
}

